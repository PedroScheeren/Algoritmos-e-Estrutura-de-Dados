#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia, mes,ano;
}Data;

typedef struct
{
    char nome[50];
    Data data;
}Pessoa;

typedef struct no
{
    Pessoa p;
    struct no *proximo;
    
}No;

Pessoa ler_pessoa() ;
void imprimir_pessoa(Pessoa p);
No* empilhar(No *topo);
No *pop(No **topo);
void imprimir_pilha(No *topo);

int main() {

    No *remover,*topo = NULL;
    int opcao;

    do {
        printf("\n\t0 - sair \n\t 1 - empilhar \n\t 2 - desempilhar \n\t 3 - imprimir\n");
        scanf("%d", &opcao);
        getchar();
        printf("\n opcao = %d", opcao);
  
        switch (opcao)
        {
        case 1:
            topo = empilhar(topo);
            break;
        case 2:
            remover = pop(&topo);
            break;
        case 3:
            imprimir_pilha(topo);
            break;
        default:
            if(opcao != 0){
                printf("\n opcao invalida\n");
            }
        
        }
    } while (opcao != 0);

    return 0;

}

Pessoa ler_pessoa() {
    Pessoa p;
    
    printf("\n Digite o nome, data de nascimento dd mm aaaa: \n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
   
    return p;
}

void imprimir_pessoa(Pessoa p) {
    printf("\n Nome : %s\n Data: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);

}

// Operação push = empilhar
No* empilhar(No *topo){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    } 
    else {
        printf("\n Erro na alocação \n");
    }
    return NULL;
}

No *pop(No **topo){

    if(*topo){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else{
        printf("Pilha vazia\n\n");
    }

}
void imprimir_pilha(No *topo){

    if (topo)
    {
      printf("\n------------PILHA------------\n");
    while (topo)
    {
        imprimir_pessoa(topo->p);
        topo = topo->proximo;
    }
    printf("------------FIM------------\n");
    }else
        printf("\n\nPilha vazia");
    
    
}