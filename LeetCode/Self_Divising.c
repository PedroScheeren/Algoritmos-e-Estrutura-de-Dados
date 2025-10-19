//LeetCode - 728 -

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* selfDividingNumbers(int left, int right, int* returnSize);
bool isSelfDividing(int n);


int main(){
    int left = 1, right = 22;
    int size;
    int* resultado = selfDividingNumbers(left, right, &size);

    printf("Números self-dividing entre %d e %d:\n", left, right);
    for (int i = 0; i < size; i++) {
        printf("%d ", resultado[i]);
    }

    free(resultado); // libera a memória
    return 0;
}

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int *lista = (int *)malloc((right -left + 1) * sizeof(int));
    int count = 0;

    if (!lista){
        printf("Erro ao alcoar");
        exit(1);
    }
    
    for (int i = left; i <= right; i++){
        if (isSelfDividing(i))
        {
            lista[count++] = i;
        }
    }

    *returnSize = count;
    return lista;
    
}

bool isSelfDividing(int n){
    int temp = n;
    
    while (temp>0){
        int digito = temp %10;

        if(digito == 0 || n % digito != 0)
            return false;
        
        temp/=10;
    }
    
    return true;
}