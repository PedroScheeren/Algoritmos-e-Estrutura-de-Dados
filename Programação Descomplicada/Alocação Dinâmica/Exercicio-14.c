#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int **aloca(int linhas, int colunas);
void preenche_matriz(int **matriz, int linhas, int colunas);
void imprime_matriz(int **matriz, int linhas, int colunas);
void libera_matriz(int **matriz, int linhas);


int main(){
    int **matriz;
    int linhas, colunas;

    printf("Digite o numero de linhas e colunas-> ");
    scanf("%d %d", &linhas, &colunas);


    matriz = aloca(linhas , colunas);
    preenche_matriz(matriz, linhas, colunas);
    imprime_matriz(matriz, linhas, colunas);

    libera_matriz(matriz,linhas);



    return 0;
}

int **aloca(int linhas, int colunas){
    int **matriz = (int **)malloc(linhas * sizeof(int*));

    if (!matriz)
    {
        printf("Erro ao alocar memoria");
        exit(1);
    }
    
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));

        if (!matriz[i])
        {
            printf("Erro ao alocar coluna");
            exit(1);
        }
        
    }
    return matriz;
}

void preenche_matriz(int **matriz, int linhas, int colunas){
    srand(time(NULL));

    for (int i = 0; i < linhas; i++)
    {
       for (int j = 0; j< colunas;j++)
       {
            matriz[i][j] = rand()%2;
       }
       
    }
    
}

void imprime_matriz(int **matriz, int linhas, int colunas){

    for (int i = 0; i < linhas; i++)
    {
        for(int j=0; j<colunas;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
}

void libera_matriz(int **matriz, int linhas){
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}