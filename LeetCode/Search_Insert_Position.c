//LeetCode - 14 - 
#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target);

int main(){
    int array[4] ={1,3,5,6};
    int procurado, tamanho=4;

    printf("Digite o valor que desjea procurar: ");
    scanf("%d", &procurado);

    printf("\n%d\n\n", searchInsert(array,tamanho,procurado));


    return 0;
}

int searchInsert(int* nums, int numsSize, int target){
    
    for (int i = 0; i < numsSize; i++){
        if (nums[i] >= target)
            return i;
    }
    
    for (int i = 0; i < numsSize-1; i++){
        if (target > nums[i] && target < nums[i+1])
        {
            return i+1;
        }
        
    }
    
}