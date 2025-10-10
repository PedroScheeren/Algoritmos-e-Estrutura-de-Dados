#include <stdio.h>


int calcula_fatorial(int n);


int main(){
    int n;

    printf("Digite o valor N: ");
    scanf("%d",&n);

    printf("Fatorial eh -> %d\n\n", calcula_fatorial(n));


    return 0;
}

int calcula_fatorial(int n){
    int fatorial=1;

    for (int i = n; i > 0; i--)
    {
        fatorial *= i;
    }
    
    return fatorial;
}