#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados {
    char nome[30];
    int idade;
    char endereco[50];
    struct dados *proximo;
};

typedef struct dados pessoa;

int menu();
pessoa* cria(void);
void insere(pessoa *lista);
void le_dados(pessoa *n);
void listar(pessoa *lista);

int main() {
    pessoa *lista = cria();

    for (;;) {
        switch (menu()) {
        case 1:
            insere(lista);
            break;
        case 2:
        listar(lista);
        break;
        case 3:
            printf("Operacao encerrada\n");
            exit(0);
        default:
            printf("Opcao invalida\n");
            break;
        }
    }
    return 0;
}

int menu() {
    int opcao;
    printf("\nOPCOES DISPONIVEIS:\n");
    printf("1. Inserir\n2. Listas\n3.Sair\n->");
    scanf("%d", &opcao);
    getchar(); 
    return opcao;
}

pessoa* cria(void) {
    pessoa *cabeca = (pessoa*) malloc(sizeof(pessoa));
    if (!cabeca) {
        printf("Erro ao gerar cabeca\n");
        exit(1);
    }
    cabeca->proximo = NULL;
    return cabeca;
}

void insere(pessoa *lista) {
    pessoa nova;
    le_dados(&nova);

    pessoa *novo = (pessoa*) malloc(sizeof(pessoa));
    if (!novo) {
        printf("Erro ao alocar nova celula\n");
        exit(1);
    }

    *novo = nova;     // copia todos os campos
    novo->proximo = lista->proximo;
    lista->proximo = novo;
}

void le_dados(pessoa *p) {
    printf("Digite o nome: ");
    scanf(" %[^\n]", p->nome);
    getchar();
    printf("Digite o endereco: ");
    scanf(" %[^\n]", p->endereco);
    getchar();
    printf("Digite a idade: ");
    scanf("%d", &p->idade);
    getchar();
}

void listar(pessoa *lista){
    pessoa *aux= lista->proximo;

    while (aux!=NULL){
        printf("%s;%s;%d", aux->nome,aux->endereco,aux->idade);
        
        if (aux->proximo !=NULL)
        {
            printf("\n");
        }
         aux = aux->proximo;
    }
}