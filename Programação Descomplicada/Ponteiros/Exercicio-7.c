#include <stdio.h>

void soma(int *p1, int *p2);


int main(){
    int a, b;

    printf("Digite o valor de A e B: ");
    scanf("%d%d", &a,&b);

    soma(&a,&b);

    printf("O valor de A: %d\nO valor de B: %d\n\n", a, b);


    return 0;
}

void soma(int *p1, int *p2){
      *p1 += *p2;
}