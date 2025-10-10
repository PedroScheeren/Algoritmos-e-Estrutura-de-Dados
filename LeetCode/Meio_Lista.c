//LeetCode - 876 -
#include <stdio.h>
#include <stdlib.h>


struct valor{
    int val;
    struct valor *proximo;

};

typedef struct valor No;

No *cria_cabeca(void);
void insere(No *lista, int valor);
No *middleNode(No *lista);



int main(){
    int n;
    No *lista;
    No *meio;

    lista = cria_cabeca();
    printf("Digite a quantidade que deseja reservar-> ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int valor;
        printf("Numero %d: ", i +1);
        scanf("%d", &valor);
        insere(lista,valor);
    }
    
    meio = middleNode(lista);

    printf("O valor do meio: %d\n\n", meio->val);

    free(lista);
    free(meio);


    return 0;
}

No *cria_cabeca(void){
    No *start = (No *)malloc(sizeof(No));

    if (!start)
    {
        printf("Erro ao criar cabeca");
        exit(1);
    }
    start->proximo = NULL;

    return start;
}

void insere(No *lista, int valor){
    No *novo = (No *)malloc(sizeof(No));
    
    if (!novo)
    {
        printf("Erro ao alocar memoria");
        exit(1);
    }
    
    
    novo->val = valor;
    novo->proximo = NULL;

  
        No *aux = lista;
        while (aux->proximo !=NULL)
        {
            aux = aux->proximo;
        }
        aux -> proximo= novo;
}
    
No *middleNode(No *lista){
    No *aux = lista->proximo;
    int count=0;

    while (aux!=NULL)
    {
        count++;
        aux = aux->proximo;
    }
    
    int meio = count/2;

    aux = lista->proximo;

    for (int i = 0; i < meio; i++)
    {
        aux= aux->proximo;
    }
    
    return aux;
}