#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *aloca(int n);
int *guarda_valores(int *alocado, int *p1, int *p2);
int conta_valores(int *p1, int *p2);

int main(){
    int num_loteria[6];
    int num_jogados[6];
    int contador=0;
    int *num_corretos;


    srand(time(NULL)); // cria uma "semente" com o tempo atual

    printf("Numeros sorteados:\n");
    for (int i = 0; i < 6; i++){
        num_loteria[i] = rand() % 10; //função rand ira gerar numeros entre 0 e 9
        printf("%d ", num_loteria[i]);
    }
    
    printf("\nNumeros comprados:\n");
    for (int i = 0; i < 6; i++){
        num_jogados[i] = rand() % 10;
        printf("%d ", num_jogados[i]);
    }
    
    contador = conta_valores(num_loteria, num_jogados);

    printf("\nAcertos:\n%d",contador);

    if (contador>0){
          num_corretos = aloca(contador);
          num_corretos = guarda_valores(num_corretos,num_loteria,num_jogados);
    }
    
    printf("\nNumeros Corretos:\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%d ", num_corretos[i]);
    }
    
    printf("\n\n\n\n");

    free(num_corretos);
 
   


    return 0;
}
  
int *aloca(int n){
    int *ponteiro = (int *)malloc(n*sizeof(int));
    
    if (!ponteiro)
    {
        printf("Erro ao alocar");
        exit(1);
    }
    
    
    return ponteiro;

}

int *guarda_valores(int *alocado, int *p1, int *p2){
    int *aux = alocado;
    int k=0;
     for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++){
            
            if (p1[i] == p2[j])
            {
               aux[k++] = p2[j];
               break;
            }
            
        }
     }

     return aux;
}


int conta_valores(int *p1, int *p2){
    int contador=0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++){
            
            if (p1[i] == p2[j])
            {
               contador++;
               break;
            }
            
        }
        
    }
    return contador;

}