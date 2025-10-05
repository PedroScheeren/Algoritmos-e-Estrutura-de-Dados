#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int **aloca_matriz(int linhas, int colunas);
void preenche_matriz(int **matriz, int linhas, int colunas);
void imprime_matriz(int **matriz, int linhas, int colunas);
int confere_numero(int **matriz,int linhas, int colunas, int valor, int indice[]);
void libera_matriz(int **matriz, int linhas);


int main(){

    int **matriz;
    int linhas, colunas;
    int n; // valor a ser procurado
    int indice[2];



    printf("Digite quantas linhas e colunas tera a matriz -> ");
    scanf("%d %d", &linhas, &colunas);
    printf("Digite o valor que deseja procurar-> ");
    scanf("%d", &n);

    matriz = aloca_matriz(linhas,colunas);

    preenche_matriz(matriz,linhas,colunas);

    if(confere_numero(matriz,linhas,colunas,n,indice)){
        printf("Valor %d encontrado na posicao %d:%d!\n", n, indice[0],indice[1]);
    }else{
        printf("valor %d nao encontrado\n",n);
    }

    printf("Matriz gerada:\n");
    imprime_matriz(matriz,linhas,colunas);

    libera_matriz(matriz,linhas);


    return 0;
}

int **aloca_matriz(int linhas, int colunas){
    int **matriz = (int **)malloc(linhas * sizeof(int *));

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
            printf("Erro ao alocar matriz");
            exit(1);
        }
        
    }
    return matriz;
}

void preenche_matriz(int **matriz, int linhas, int colunas){
        
    srand(time(NULL)); //cria uma semente aleatoria

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            matriz[i][j] = rand() % 99; // recebe valores de 0 a 99
        }
        
    }
}

void imprime_matriz(int **matriz, int linhas, int colunas){
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int confere_numero(int **matriz,int linhas, int colunas, int valor, int indice[]){
    
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if(valor == matriz[i][j]){
                indice[0] = i;
                indice[1]= j;
                return 1;
            }
        }
        
    }
    return 0;
}

void libera_matriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
