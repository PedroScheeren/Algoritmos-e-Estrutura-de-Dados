#include <stdio.h>
#include <stdlib.h>




int main(){
    int *valores = (int *) calloc(1500, sizeof(int));
    int count=0;

    for (int i = 0; i < 1500; i++){
        
        if (valores[i]==0)
            count++;
    }

    if (count != 1500) {
        printf("Nao alocou 1500 zeros");
        exit(1);
    }
    
    for (int i = 0; i < 1500; i++)
    {
       valores[i] = i;
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("%d %d\n", valores[i], valores[1499-i]);
    }
    
    printf("\n");

    free(valores);

    return 0;
}