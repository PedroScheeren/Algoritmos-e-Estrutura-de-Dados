//LeetCode - 283 -

#include <stdio.h>
#include<stdlib.h>

void moveZeroes(int* nums, int numsSize);

int main(){
    int array[5] = {0,1,0,3,12};
    int tamanho = 5;

    moveZeroes(array,tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]);
    }
    
    return 0;
}

void moveZeroes(int* nums, int numsSize){

     int j = 0;
    
    // Passo 1: mover todos os não-zeros para frente
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }
    
    // Passo 2: preencher o restante com zeros
    for (; j < numsSize; j++) {
        nums[j] = 0;
    }
}