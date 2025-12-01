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

typedef struct {
    No *topo;
    int tam;
}Pilha;


void criar_pilha(Pilha *p);
Pessoa ler_pessoa() ;
void imprimir_pessoa(Pessoa p);
void empilhar(Pilha *p);
No *pop(Pilha *p);
void imprimir_pilha(Pilha *p);

int main() {

    No *remover;
    Pilha p;
    int opcao;


    criar_pilha(&p);

    do {
        printf("\n\t0 - sair \n\t 1 - empilhar \n\t 2 - desempilhar \n\t 3 - imprimir\n");
        scanf("%d", &opcao);
        getchar();
        printf("\n opcao = %d", opcao);
  
        switch (opcao)
        {
        case 1:
            empilhar(&p);
            break;
        case 2:
            remover = pop(&p);
            free (remover);
            break;
        case 3:
            imprimir_pilha(&p);
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
void empilhar(Pilha *p){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = p->topo;
        p->topo = novo;
        p->tam++;
    } 
    else {
        printf("\n Erro na alocação \n");
    }
   
}

No *pop(Pilha *p){

    if(p->topo){
        No *remover = p->topo;
        p->topo= remover->proximo;
        return remover;
    }
    else{
        printf("\n\nPilha vazia\n\n");
    }

}
void imprimir_pilha(Pilha *p){

    No *aux = p->topo;
    if (aux)
    {
      printf("\n------------PILHA------------\n");
    while (aux)
    {
        imprimir_pessoa(aux->p);
        aux = aux->proximo;
    }
    printf("------------FIM------------\n");
    }else
        printf("\n\nPilha vazia");
    
    
}

void criar_pilha(Pilha *p){
    p->topo = NULL;
    p->tam = 0;
}