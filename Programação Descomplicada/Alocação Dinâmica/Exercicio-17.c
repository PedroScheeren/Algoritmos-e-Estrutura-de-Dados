#include <stdio.h>
#include <stdlib.h>

int *aloca(int tamanho);

int main() {
    int n, qtd = 0;
    int *lista = NULL;

    do {
        printf("Digite qualquer valor (0 para sair): ");
        scanf("%d", &n);

        if (n == 0)
            break;

        // aumenta o tamanho e realoca memória
        qtd++;
        lista = aloca(qtd);

        // armazena o novo valor
        lista[qtd - 1] = n;

    } while (n != 0);

    printf("\nValores digitados:\n");
    for (int i = 0; i < qtd; i++)
        printf("%d ", lista[i]);

    free(lista);
    return 0;
}

int *aloca(int tamanho) {
    int *ptr = realloc(NULL, tamanho * sizeof(int)); // realloc com NULL = malloc
    if (!ptr) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    return ptr;
}
