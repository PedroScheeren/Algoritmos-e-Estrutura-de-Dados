#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
} No;

void inserir_fila(No **fila, int num);
No* remover_fila(No **fila);
void imprimir_fila(No *fila);

int main(){
    int opc, num;
    No *fila = NULL;   // CORREÇÃO IMPORTANTE!

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
            imprimir_fila(fila);
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

void inserir_fila(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));

    if (novo){
        novo->valor = num;
        novo->proximo = NULL;

        if (!*fila){
            *fila = novo;
        } else {
            aux = *fila;
            while (aux->proximo)
                aux = aux->proximo;

            aux->proximo = novo;
        }
    } else {
        printf("Erro ao alocar memoria!\n");
    }
}

No* remover_fila(No **fila){
    No *remover = NULL;

    if (*fila){
        remover = *fila;
        *fila = remover->proximo;
    } else {
        printf("\nFila vazia!\n");
    }

    return remover;
}

void imprimir_fila(No *fila){
    printf("\n--------- FILA ---------\n");
    while (fila){
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    printf("\n------------------------\n");
}
