#include <stdio.h>
#include <stdlib.h>


int *aloca(int n);
void confere_par_impar (int *p, int n, int *pares, int *impar);



int main(){

    int n;
    int *array;
    int pares=0, impares=0;

    printf("Digite a quantidade de valores que deseja ler -> ");
    scanf("%d", &n);

    array = aloca(n);

    for (int i = 0; i < n; i++)
    {
        printf("\nDigite o valor %d ->  ", i+1 );
        scanf("%d", &array[i]);
    }

    confere_par_impar(array, n, &pares, &impares);

    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\nO numero de pares -> %d\nO numero de impares -> %d\n\n", pares,impares);

    return 0;
}

int *aloca(int n){
    int *ponteiro = (int *)malloc(n*sizeof(int));

    if (!ponteiro) {
        printf("Erro ao alocar memoria");
        exit(1);
    }
    
    return ponteiro;
}
void confere_par_impar (int *p, int n, int *pares, int *impar){
    
    for (int i = 0; i < n; i++)
    {
        if (p[i]%2==0)
        {
            (*pares)++;
        }else   
            (*impar)++;
        
    }
    
}