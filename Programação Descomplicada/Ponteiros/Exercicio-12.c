#include <stdio.h>


int ordena(int *lista, int *lista_ordenada,int n);

int main(){
    int lista_ordenada[3];
    int lista[3];

    printf("Digite os valores A,B e C: ");
    for (int i = 0; i < 3; i++)
    {
      scanf("%d",&lista[i]);
    }
    
    

    if (ordena(lista,lista_ordenada,3))
        printf("Valores iguais\n");
    
    else{
        
        printf("Valores ordenados:\n");
        
        for (int i = 0; i < 3; i++)
        {
            printf("%d ", lista_ordenada[i]);
        }
        
    }
    
    return 0;
}

int ordena(int *lista, int *lista_ordenada, int n){

    for (int i = 0; i < n; i++) {
        lista_ordenada[i] = lista[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (lista_ordenada[i] > lista_ordenada[j]) {
                int aux = lista_ordenada[i];
                lista_ordenada[i] = lista_ordenada[j];
                lista_ordenada[j] = aux;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (lista_ordenada[i] == lista_ordenada[i + 1]) {
            return 1; 
        }
    }

    return 0;
}
