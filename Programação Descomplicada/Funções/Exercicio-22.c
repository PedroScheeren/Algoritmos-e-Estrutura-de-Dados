#include <stdio.h>

void gera_sequencia(int n);

int main(){

    int quantidade;

    printf("Digite a quantidade desejada:");
    scanf("%d", &quantidade);

    gera_sequencia(quantidade);
    return 0;
}

void gera_sequencia(int n){

    for (int i = 0; i < n; i++){
         for(int j = 0; j<=i; j++){
        printf("!");
        }
    printf("\n");

    }
}