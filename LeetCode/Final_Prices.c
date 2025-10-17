//LeetCode - 1475 -

#include <stdio.h>
#include <stdlib.h>

int* finalPrices(int* prices, int pricesSize, int* returnSize);

int main(){
    int array[5]={8,4,6,2,3};
    int pricesSize=5;
    int *out;
    int outSize=0;

   out=finalPrices(array,pricesSize,&outSize);

    for (int i = 0; i < 5; i++){
        printf("%d ",out[i]);
    }
    
    printf("\n\n");




    return 0;
}

int* finalPrices(int* prices, int pricesSize, int* returnSize){

    int* result = (int *)malloc(pricesSize * sizeof(int));
    int stack[pricesSize];
    int top=-1;

    for (int i = 0; i < pricesSize; i++){
        while (top>=0 && prices[i]<=prices[stack[top]]){
            int idx = stack[top--];
            result[idx] = prices[idx] - prices[i];
        }
        stack[++top] = i;
    }
     while (top >= 0) {
        int idx = stack[top--];
        result[idx] = prices[idx];
    }

    *returnSize = pricesSize;
    return result;

}