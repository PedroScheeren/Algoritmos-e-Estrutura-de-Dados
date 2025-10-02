#include <stdio.h>
#include <stdlib.h>


int * aloca(int n);

int main(){
    int *array;
    int n;


    printf("Digite a quantidade que deseja alocar-> ");
    scanf("%d", &n);

      array  = aloca(n);

    for (int i = 0; i < n; i++){
        printf("Digite o valor %d:", i+1);
        scanf("%d", &array[i]);
        printf("\n");
    }
    
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    free(array);
    
    return 0;
}

int* aloca(int n){
    int *ponteiro = (int *)malloc(n * sizeof(int));
    
    
    
    if (!ponteiro){
        printf("Erro ao alocar memoria");
        exit(1);
    }
    
    return ponteiro;

}