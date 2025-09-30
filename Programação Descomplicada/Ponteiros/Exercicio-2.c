#include <stdio.h>


int main(){

    int valor1, valor2;

if (&valor1 > &valor2){
    printf("O endereco do valor 1 eh maior\n");
    printf("valor 1:%p\nvalor 2:%p\n",&valor1,&valor2);
}
   
else{
    printf("O endereco do valor 2 eh maior\n");
    printf("valor 1:%p\nvalor 2:%p\n",&valor1,&valor2);
}
    return 0;
}