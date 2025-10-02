#include <stdio.h>

float calcula_nota(float n[], char metodo);

int main() {
    char letra;
    float notas[3];
    int op;

    do {
        for (int i = 0; i < 3; i++) {
            printf("Digite a Nota %d -> ", i+1);
            scanf("%f", &notas[i]);
        }

        printf("Digite o metodo (A = media aritmetica, P = media ponderada): ");
        scanf(" %c", &letra);

        printf("O valor eh -> %.2f\n", calcula_nota(notas, letra));

        printf("Deseja continuar? 1-SIM 2-NAO: ");
        scanf("%d", &op);

    } while (op == 1);

    return 0;
}

float calcula_nota(float n[], char metodo) {
    float resultado = 0;

    if (metodo == 'A' || metodo == 'a') {
        resultado = (n[0] + n[1] + n[2]) / 3.0;
    }
    else if (metodo == 'P' || metodo == 'p') {
        resultado = (n[0]*5 + n[1]*3 + n[2]*2) / 10.0;
    }
    else {
        printf("Metodo invalido!\n");
    }

    return resultado;
}
