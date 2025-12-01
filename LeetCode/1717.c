#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removePairs(const char *s, char a, char b, char *output);
int maximumGain(char *s, int x, int y);

int main() {
    char s[] = "cdbcbbaaabab";
    int x = 4, y = 5;

    int result = maximumGain(s, x, y);
    printf("Resultado: %d\n", result);

    return 0;
}

// Função que remove pares (a,b) usando pilha dinâmica
int removePairs(const char *s, char a, char b, char *output) {
    char *stack = NULL;    // pilha dinâmica
    int size = 0;          // tamanho atual da pilha
    int removed = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        // Verifica se forma o par alvo (a,b)
        if (size > 0 && stack[size - 1] == a && c == b) {
            // POP
            size--;
            stack = realloc(stack, size * sizeof(char));
            removed++;
        } else {
            // PUSH
            size++;
            stack = realloc(stack, size * sizeof(char));
            stack[size - 1] = c;
        }
    }

    // Copiar a pilha resultante para output
    for (int i = 0; i < size; i++) {
        output[i] = stack[i];
    }
    output[size] = '\0';

    free(stack);
    return removed;
}

// Função principal: calcula pontuação máxima
int maximumGain(char *s, int x, int y) {
    int n = strlen(s);
    char *temp1 = malloc(n + 1);
    char *temp2 = malloc(n + 1);

    int total = 0;

    if (x > y) {
        // Primeiro remove "ab"
        int removeHigh = removePairs(s, 'a', 'b', temp1);
        total += removeHigh * x;

        // Depois remove "ba"
        int removeLow = removePairs(temp1, 'b', 'a', temp2);
        total += removeLow * y;

    } else {
        // Primeiro remove "ba"
        int removeHigh = removePairs(s, 'b', 'a', temp1);
        total += removeHigh * y;

        // Depois remove "ab"
        int removeLow = removePairs(temp1, 'a', 'b', temp2);
        total += removeLow * x;
    }

    free(temp1);
    free(temp2);
    return total;
}