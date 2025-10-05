#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char nome[30];
    int dia, mes, ano;
}alunos;

alunos * aloca(int n);
void registra_aluno(alunos *alocado, int n);
void imprime_array(alunos *array, int n);



int main(){

    alunos *array;
    int n;

    printf("Digite a quantidade de alunos que deseja armanezar-> ");
    scanf("%d", &n);


    array = aloca(n);
    
    registra_aluno(array,n);
    imprime_array(array,n);

    free(array);

    return 0;
}

alunos * aloca(int n){
    alunos *ponteiro = (alunos *)malloc(n*sizeof(alunos));
    return ponteiro;
}

void registra_aluno(alunos *alocado, int n){
    for (int i = 0; i < n; i++)
    {
        printf("Digite a matricula do aluno %d-> ", i+1);
        scanf("%d", &alocado[i].matricula);
        
        getchar();
        
        printf("Digite o nome do aluno %d-> ", i+1);
        fgets(alocado[i].nome, 30, stdin);
        
        printf("Digite a data de nascimento do aluno %d (dd mm aaaa)-> ", i+1);
        scanf("%d %d %d", &alocado[i].dia, &alocado[i].mes, &alocado[i].ano);
    }
}

void imprime_array(alunos *array, int n){
    for (int i = 0; i < n; i++)
    {
        printf("\nAluno %d: %d - %s - %02d/%02d/%04d\n", i+1, array[i].matricula, array[i].nome,array[i].dia,array[i].mes,array[i].ano);
    }
}
