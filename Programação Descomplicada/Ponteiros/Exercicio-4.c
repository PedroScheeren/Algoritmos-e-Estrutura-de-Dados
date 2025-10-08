#include <stdio.h>

void troca_valores(int *p1, int *p2);

int main(){
    int a=10;
    int b=20;

    printf("P1: %d\nP2:%d\n",a,b);

    troca_valores(&a,&b);

    printf("P1: %d\nP2:%d\n",a,b);


    return 0;
}

void troca_valores(int *p1, int *p2){
    int aux = *p1;
   
    *p1 = *p2;
    *p2 = aux;
    printf("Valores trocados\n");
}