#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int x, y;
    int maior;
}maior;

int **aloca(int linhas, int colunas);
void preenche_matriz(int **matriz, int linhas, int colunas);
void localiza_maior(int **matriz,int linhas, int colunas, maior maiores[]);
void imprime_matriz(int **matriz,int linhas, int colunas, maior maiores[]);
void libera(int **matriz, int linhas);



int main(){
    int **matriz;
    int linhas, colunas;
    maior vetor[3];

    printf("Digite a quantidade de linhas e colunas: ");
    scanf("%d%d", &linhas, &colunas);

    matriz = aloca(linhas,colunas);
    preenche_matriz(matriz,linhas,colunas);
    localiza_maior(matriz,linhas,colunas,vetor);
    imprime_matriz(matriz,linhas,colunas,vetor);
    libera(matriz,linhas);      



    return 0;
}

int **aloca(int linhas, int colunas){
    int **matriz = (int **)malloc(linhas*sizeof(int *));

    if (!matriz)
    {
       printf("Erro ao alocar matriz");
       exit(1);
    }
    
    for (int i = 0; i < colunas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));

        if (!matriz[i])
        {
            printf("Erro ao alocar memoria");
            exit(1);
        }
        
    }
    return matriz;
    
}

void preenche_matriz(int **matriz, int linhas, int colunas){
    srand(time(NULL));

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++)
        {
           
            matriz[i][j] = rand () % 99;
        }
        
    }
    
}

void localiza_maior(int **matriz,int linhas, int colunas, maior maiores[]){
    int k=0;
    maiores[0].maior = matriz[0][0];
    maiores[1].maior = matriz[0][0];
    maiores[2].maior = matriz[0][0];

     for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++)
        {
           if (maiores[k].maior < matriz[i][j])
           {
                maiores[k].maior = matriz[i][j];
                maiores[k].x = i;
                maiores[k].y = j;
                k++;

                if (k == 2)
                    break;
            }
   
        }
        
    }
    
}

void imprime_matriz(int **matriz,int linhas, int colunas, maior maiores[]){
    
    printf("Os maiores valores sao:\n");
    
    for (int i = 0; i < 3; i++)
        printf("%d -> (%d,%d)\n", maiores[i].maior,maiores[i].x,maiores[i].y);
    
    
    printf("A matriz gerada:\n");
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++)
        {
           
          printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
}

void libera(int **matriz, int linhas){
    for (int i = 0; i < linhas; i++)
        free(matriz[i]);

    free(matriz);
    
}