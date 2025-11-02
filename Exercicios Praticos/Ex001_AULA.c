//Pedro de Freitas Scheeren
//LeetCode 860

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize);

int main(){
    int vetor_limonada[5]={5,5,5,10,20};
    int tamanho = 5;

    if(lemonadeChange(vetor_limonada,tamanho))
        printf("TRUE\n\n");
    else
        printf("ELSE\n\n");

    return 0;
}

bool lemonadeChange(int* bills, int billsSize){
    int notas_5=0;
    int notas_10=0;
    int count = 0;

    for (int i = 0; i < billsSize; i++){
        if (bills[i]==5){
           notas_5++;
           count++;
        }
        else if(bills[i]==10 && notas_5>=1){
            notas_10++;
            notas_5--;
            count++;
        }
        else if (bills[i]==20 && (notas_10>=1 && notas_5>=1)){
            notas_10--;
            notas_5--;
            count++;    
        }
        else if (bills[i]==20 && notas_5>=3){
            notas_5 = notas_5-3;
            count++;
        }
    }

    if (count == billsSize)
        return true;
    
    return false;
    
}
