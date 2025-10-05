#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int id;
    char nome[50];
    int estoque;
    float valor;

}produto;


produto *aloca(int n);
void registra(produto *lista, int n);
void localiza_maior(produto *lista, int n, int *estoque, float *valor);
void imprime(produto *lista, int n, int maior_est, float maior_venda);

int main(){

    int n, maior_estoque;
    float maior_venda;
    produto *array;

    printf("Digite a quantidade de produtos: ");
    scanf("%d",&n);
    
    array=aloca(n);

    registra(array,n);
    localiza_maior(array,n,&maior_estoque,&maior_venda);
    imprime(array,n,maior_estoque,maior_venda);

    free(array);
    
    return 0;
}

produto *aloca(int n){
    produto *ponteiro = (produto *)malloc(n*sizeof(produto));

    if (!ponteiro){
        printf("Erro ao alocar memoria");
        exit(1);
    }

    return ponteiro;
    
}

void registra(produto *lista, int n){

    for (int i = 0; i < n; i++)
    {
        printf("Digite o ID do produto %d: ", i+1);
        scanf("%d",&lista[i].id);
        getchar();
        printf("Digite o nome do produto %d: ",i+1);
        fgets(lista[i].nome,30,stdin);
        lista[i].nome[strcspn(lista[i].nome, "\n")] ='\0';
        printf("Digite a quantidade em estoque do produto %d: ", i+1);
        scanf("%d", &lista[i].estoque);
        printf("Digite o valor do produto %d: ",i+1);
        scanf("%f", &lista[i].valor);
    }
    
}

void localiza_maior(produto *lista, int n, int *estoque, float *valor){
    
    *estoque = lista[0].estoque;
    *valor = lista[0].valor;
    
    for (int i = 0; i < n; i++)
    {
       if (*estoque < lista[i].estoque)
       {
            *estoque = lista[i].estoque;
       }
       
       if (*valor < lista[i].valor)
       {
            *valor = lista[i].valor;
       }
       
    }
    

}

void imprime(produto *lista, int n, int maior_est, float maior_venda){
    for (int i = 0; i < n; i++)
    {
        printf("\n\n%d - %s - %d - %f\n\n", lista[i].id, lista[i].nome,lista[i].estoque,lista[i].valor);
    }
    printf("Maior estoque-> %d\nMaior preco-> %f", maior_est, maior_venda);
    printf("\n\n");
}