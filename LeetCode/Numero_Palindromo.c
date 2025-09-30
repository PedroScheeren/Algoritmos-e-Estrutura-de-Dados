
#include <stdio.h>

int eh_palindromo(int n);

int main(){

int numero, op;
    
do
{
    printf("Digite o numero a ser testado: ");
    scanf("%d", &numero);
    if (eh_palindromo(numero)){
        printf("Eh palindromo\n");
    }
    else{
        printf("Nao eh palindromo\n\n");
    }

    printf("1-Testar outro valor\n2-Sair\n->");
    scanf("%d", &op);

} while (op==1);



    return 0;
}

int eh_palindromo(int n){
    int original, resto, reverso = 0;
    
    if (n < 0 )
        return 0;
    
    
    original = n;

    while (n != 0){
        resto = n % 10;
        reverso = (reverso * 10) + resto;
        n /= 10;
    }
    
    if (original == reverso)
        return 1;
    else
        return 0;

}