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

}Fila;


void criar_fila(Fila *fila);
void inserir_fila(Fila*fila, int num);
No* remover_fila(Fila *fila);
void imprimir_fila(Fila *fila);

int main(){
    int opc, num;
    Fila fila;

    criar_fila(&fila);

    do {
        printf("\n=====================================\n");
        printf("               MENU                  \n");
        printf("=====================================\n");
        printf("  0 - Sair\n");
        printf("  1 - Inserir\n");
        printf("  2 - Remover\n");
        printf("  3 - Imprimir\n");
        printf("-------------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        switch (opc){
        
        case 1:
            printf("Digite o numero a ser inserido -> ");
            scanf("%d", &num);
            inserir_fila(&fila, num);
            break;

        case 2: {
            No *rem = remover_fila(&fila);
            if (rem){
                printf("Removido: %d\n", rem->valor);
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

void inserir_fila(Fila *fila, int num){
    No *aux, *novo = malloc(sizeof(No));

    if (novo){
        novo->valor = num;
        novo->proximo = NULL;

        if (!fila->primeiro){
            fila->primeiro = novo;
            fila->fim = novo;
            fila->tam++;
        } else {
            fila->fim->proximo = novo;
            fila->fim = novo;
            fila->tam++;
        }
    } else {
        printf("Erro ao alocar memoria!\n");
    }
}

No* remover_fila(Fila *fila){
    No *remover = NULL;

    if (fila->primeiro){
        remover = fila->primeiro;
        fila->primeiro = remover->proximo;
        fila->tam--;
    } else {
        printf("\nFila vazia!\n");
    }

    return remover;
}

void imprimir_fila(Fila *fila){
    No *aux = fila->primeiro;
    printf("\n--------- FILA ---------\n");
    while (aux){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n------------------------\n");
}