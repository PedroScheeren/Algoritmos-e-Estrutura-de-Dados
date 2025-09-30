#include <stdio.h>

void soma_vetor(int *nums, int numsSize, int target, int *returnSize);

int main() {
    int vetor[4] = {2, 7, 11, 15};
    int procurado;
    int resposta[2];

    printf("Digite o valor N: ");
    scanf("%d", &procurado);

    soma_vetor(vetor, 4, procurado, resposta);

    printf("Índices: %d %d\n", resposta[0], resposta[1]);

    return 0;
}

void soma_vetor(int *nums, int numsSize, int target, int *returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {  
            if (nums[i] + nums[j] == target) {
                returnSize[0] = i;  
                returnSize[1] = j;
                return; 
            }
        }
    }
}
