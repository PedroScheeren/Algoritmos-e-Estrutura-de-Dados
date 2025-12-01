#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
} No;

typedef struct{
    No *primeiro;
    No *fim;
    int tam;
} Fila;

// PROTÓTIPOS
void criar_fila(Fila *fila);
void inserir_prioridade(Fila *fila, int num);
No* remover_fila(Fila *fila);
void imprimir_fila(Fila *fila);

int main(){
    int opc, num;
    Fila fila;

    criar_fila(&fila);

    do {
        printf("\n=====================================\n");
        printf("           FILA DE PRIORIDADE        \n");
        printf("=====================================\n");
        printf("  0 - Sair\n");
        printf("  1 - Inserir (com prioridade)\n");
        printf("  2 - Remover (maior prioridade)\n");
        printf("  3 - Imprimir\n");
        printf("-------------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        switch (opc){
        
        case 1:
            printf("Digite o numero -> ");
            scanf("%d", &num);
            inserir_prioridade(&fila, num);
            break;

        case 2: {
            No *rem = remover_fila(&fila);
            if (rem){
                printf("\nRemovido (maior prioridade): %d\n", rem->valor);
                free(rem);
            }
            break;
        }

        case 3:
            imprimir_fila(&fila);
            break;

        case 0:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opcao Invalida!\n");
        }

    } while (opc != 0);

    return 0;
}

void criar_fila(Fila *fila){
    fila->primeiro = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

// ===============================
// INSERÇÃO COM PRIORIDADE
// Menores valores = maior prioridade
// ===============================
void inserir_prioridade(Fila *fila, int num){
    No *aux, *anterior = NULL;
    No *novo = malloc(sizeof(No));

    if (!novo){
        printf("Erro ao alocar memoria!\n");
        return;
    }

    novo->valor = num;
    novo->proximo = NULL;

    // Caso 1: fila vazia
    if (!fila->primeiro){
        fila->primeiro = novo;
        fila->fim = novo;
        fila->tam++;
        return;
    }

    aux = fila->primeiro;

    // Caso 2: inserir no início (nova maior prioridade)
    if (num < aux->valor){
        novo->proximo = fila->primeiro;
        fila->primeiro = novo;
        fila->tam++;
        return;
    }

    // Caso 3: inserir no meio ou no fim
    while (aux && aux->valor <= num){
        anterior = aux;
        aux = aux->proximo;
    }

    // Inserir entre anterior e aux
    novo->proximo = aux;
    anterior->proximo = novo;

    // Atualizar fim se inseriu no final
    if (!aux){
        fila->fim = novo;
    }

    fila->tam++;
}

No* remover_fila(Fila *fila){
    No *remover;

    if (!fila->primeiro){
        printf("\nFila vazia!\n");
        return NULL;
    }

    remover = fila->primeiro;
    fila->primeiro = remover->proximo;

    // Se removeu o último
    if (!fila->primeiro){
        fila->fim = NULL;
    }

    fila->tam--;
    return remover;
}

void imprimir_fila(Fila *fila){
    No *aux = fila->primeiro;

    printf("\n------- FILA PRIORIDADE -------\n");
    while (aux){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n--------------------------------\n");
}
