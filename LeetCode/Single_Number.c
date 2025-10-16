//LeetCode - 136 -

#include <stdio.h>

int singleNumber(int* nums, int numsSize);


int main(){

    int vetor[5]={1,1,2,1,2};
    int tam=5;


    printf("\n%d\n", singleNumber(vetor,tam));

    return 0;
}

int singleNumber(int* nums, int numsSize){
   for (int i = 0; i < numsSize; i++) {
        int contador = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                contador++;
            }
        }
        if (contador == 1) {
            return nums[i];
        }
    }
    return -1;

}