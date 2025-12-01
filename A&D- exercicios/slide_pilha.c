#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char nome[30];
    int idade;
} Pessoa;

typedef struct {
    Pessoa *pessoas;
    Pessoa *topo;
    Pessoa *base;
    int limite;
} Pilha;

void Reset(Pilha *pilha, int limite);
bool Empty(Pilha *pilha);
bool Full(Pilha *pilha);
void Push(Pilha *pilha, Pessoa nova);
Pessoa Pop(Pilha *pilha);
void Clear(Pilha *pilha);
void Delete(Pilha *pilha, char *nome);
void PrintPilha(Pilha *pilha);

int main() {
    Pilha pilha;
    Reset(&pilha, 10);

    int opc;
    Pessoa p;
    char nome[30];

    do {
        printf("\nMENU:\n");
        printf("0 - Inserir pessoa\n");
        printf("1 - Deletar pessoa do topo\n");
        printf("2 - Deletar pessoa por nome\n");
        printf("3 - Limpar pilha\n");
        printf("4 - Listar pessoas\n");
        printf("5 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc);
        getchar(); 

        switch (opc) {
            case 0:
                printf("Nome: ");
                fgets(p.nome, 30, stdin);
                p.nome[strcspn(p.nome, "\n")] = '\0';
                printf("Idade: ");
                scanf("%d", &p.idade);
                Push(&pilha, p);
                break;

            case 1:
                p = Pop(&pilha);
                if (p.idade != -1)
                    printf("Removido: %s (%d)\n", p.nome, p.idade);
                break;

            case 2:
                printf("Digite o nome a remover: ");
                fgets(nome, 30, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                Delete(&pilha, nome);
                break;

            case 3:
                Clear(&pilha);
                Reset(&pilha, 10);
                printf("Pilha limpa!\n");
                break;

            case 4:
                PrintPilha(&pilha);
                break;

            case 5:
                Clear(&pilha);
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opc != 5);

    return 0;
}

void Reset(Pilha *pilha, int limite) {
    pilha->pessoas = (Pessoa *) malloc(limite * sizeof(Pessoa));
    pilha->base = pilha->pessoas;
    pilha->topo = pilha->base;
    pilha->limite = limite;
}

bool Empty(Pilha *pilha) {
    return pilha->topo == pilha->base;
}

bool Full(Pilha *pilha) {
    return (pilha->topo - pilha->base) == pilha->limite;
}

void Push(Pilha *pilha, Pessoa nova) {
    if (Full(pilha)) {
        printf("Pilha cheia!\n");
        return;
    }
    *(pilha->topo) = nova;
    pilha->topo++;
}

Pessoa Pop(Pilha *pilha) {
    Pessoa p;
    if (Empty(pilha)) {
        printf("Pilha vazia!\n");
        strcpy(p.nome, "N/A");
        p.idade = -1;
        return p;
    }
    pilha->topo--;
    p = *(pilha->topo);
    return p;
}

void Clear(Pilha *pilha) {
    free(pilha->pessoas);
    pilha->pessoas = NULL;
    pilha->base = NULL;
    pilha->topo = NULL;
    pilha->limite = 0;
}

void Delete(Pilha *pilha, char *nome) {
    if (Empty(pilha)) {
        printf("Pilha vazia!\n");
        return;
    }

    Pilha temp;
    Reset(&temp, pilha->limite);

    Pessoa p;
    bool encontrada = false;

    while (!Empty(pilha)) {
        p = Pop(pilha);
        if (strcmp(p.nome, nome) == 0) {
            printf("Pessoa '%s' removida da pilha.\n", nome);
            encontrada = true;
            break;
        }
        Push(&temp, p);
    }

    while (!Empty(&temp))
        Push(pilha, Pop(&temp));

    Clear(&temp);

    if (!encontrada)
        printf("Pessoa '%s' não encontrada.\n", nome);
}

void PrintPilha(Pilha *pilha) {
    if (Empty(pilha)) {
        printf("Pilha vazia!\n");
        return;
    }

    Pilha temp;
    Reset(&temp, pilha->limite);

    Pessoa p;
    printf("\n--- Pessoas na pilha (do topo à base) ---\n");
    while (!Empty(pilha)) {
        p = Pop(pilha);
        printf("Nome: %s | Idade: %d\n", p.nome, p.idade);
        Push(&temp, p);
    }

    while (!Empty(&temp))
        Push(pilha, Pop(&temp));

    Clear(&temp);
}