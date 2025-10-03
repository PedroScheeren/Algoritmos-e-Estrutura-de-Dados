#include <stdio.h>
#include <stdlib.h>



int main(){

int *valores=NULL;
int contador=0;



printf("Digite um valor negativo para sair!\n\n");
while (1){
    int *tmp;
    tmp = (int *)realloc(valores, (contador+1) * sizeof(int));
   
       valores = tmp;
       
    printf("Digite o valor-> ");
    scanf("%d", &valores[contador]);

    if (valores[contador]<0)
    {
        printf("Programa encerrado\nValores lidos:\n");
        for (int i = 0; i < contador; i++)
        {
            printf("%d ", valores[i]);
        }
        break;
    }
    contador++;
 
}
    printf("\n\n\n");

    free(valores);


    return 0;
}