#include <stdio.h>

void ordena(int *a, int *b);


int main(){

    int n1, n2;
   
    printf("Digite N1 e N2: ");
    scanf("%d%d", &n1,&n2);

    ordena(&n1,&n2);

    printf("Maior valor:%d\n",n1);
    printf("Menor valor:%d\n\n",n2);


    return 0;
}

void ordena(int *a, int *b){

    if (*a < *b){
        int aux = *a;
        *a = *b;
        *b = aux;
    }
}