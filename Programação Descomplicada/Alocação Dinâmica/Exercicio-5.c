#include <stdio.h>
#include <stdlib.h>

int *aloca(int n);
int *conta_multiplos(int x, int n, int *elementos, int *contador);


int main(){
    int n, x;
    int *array, *mult;
    int contador=0;

    printf("Digite quantos valores deseja registrar -> ");
    scanf("%d", &n);
    printf("Digite o valor que deseja procurar os multiplos -> ");
    scanf("%d", &x);

    array = aloca(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    mult = conta_multiplos(x,n,array,&contador);

    printf("Os multiplos sao %d:\n", contador);
    for(int i = 0; i < contador; i++){
        printf("%d ", mult[i]);
    }
    
    printf("\n\n\n");

    return 0;
}

int *aloca(int n){
    int *ponteiro = (int *)malloc(n*sizeof(int));

    if (!ponteiro)
    {
        printf("Erro ao alocar memoria");
        exit(1);
    }
    
    return ponteiro;
}

int *conta_multiplos(int x, int n, int *elementos, int *contador){
    int *multiplos;
    
    for (int i = 0; i < n; i++){
       
        if (elementos[i] % x == 0){
            multiplos[*contador] = elementos[i];
            (*contador)++;
       }
        
    }
    
    return multiplos;
}