// LeetCode - 14 - Longest Common Prefix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main() {
    char *palavras[] = {"dog","racecar","car"};
    int tamanho = 3;

    char *resultado = longestCommonPrefix(palavras, tamanho);
    printf("Prefixo comum: %s\n", resultado);

    free(resultado);
    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    char *aux = (char*)malloc(strlen(strs[0]) + 1);
    if (!aux) {
        printf("Erro ao alocar memória para AUX\n");
        exit(1);
    }

    strcpy(aux, strs[0]); // Começa com a primeira string

    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        // Enquanto os caracteres são iguais
        while (aux[j] && strs[i][j] && aux[j] == strs[i][j]) {
            j++;
        }
        aux[j] = '\0';

        if (j == 0) {
            aux[0] = '\0';
            break;
        }
    }

    // Realoca o tamanho final exato do prefixo
    aux = realloc(aux, strlen(aux) + 1);
    if (!aux) {
        printf("Erro ao realocar memória\n");
        exit(1);
    }

    return aux;
}
