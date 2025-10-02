#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *aloca(int n);

char *remove_vogais(char *string, int n);


int main(){

    int n;
    char *string;
    char *string_sem_vogal;

   printf("Qual o tamanho da sua string -> ");
   scanf("%d", &n);
   getchar();

    string = aloca(n);

    printf("Digite a string:\n");
    fgets(string,n,stdin);
   

    string_sem_vogal = remove_vogais(string, n);

    printf("\nString sem vogais: %s\n\n\n", string_sem_vogal);
    

    free(string);

    return 0;
}

char *aloca(int n){
    char *ponteiro = (char *)malloc(n*sizeof(char));
  
    if (!ponteiro)
    {
       printf("Erro ao alocar memoria");
       exit(1);
    }
    
  
    return ponteiro;

}

char *remove_vogais(char *string, int n){
    

    for (int i = 0; i < strlen(string); i++){

        if (string[i] == 'a' || string[i] == 'A' || string[i] == 'e' || string[i] == 'E'
            || string[i] == 'i' || string[i] == 'I' || string[i] == 'o' || string[i] == 'O'
            || string[i] == 'u' || string[i] == 'U' )
        {
            string[i] = '-';
        }
        
        
    }
    
    return string;


}