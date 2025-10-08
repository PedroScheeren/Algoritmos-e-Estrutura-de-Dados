#include <stdio.h>


int dobro(int *p1, int *p2);

int main(){
    int a, b;

    printf("Digite o valor A e B: ");
    scanf("%d%d",&a,&b);

    printf("O dobro de A:%d\n dobre de B:%d\nA soma do dobro:%d\n\n", a, b, dobro(&a,&b));


    return 0;
}

int dobro(int *p1, int *p2){
    int dobroA = *p1 * 2;
    int dobroB = *p2 *2;

    *p1 = dobroA;
    *p2 = dobroB;

    dobroA += dobroB;

    return dobroA;
    
}