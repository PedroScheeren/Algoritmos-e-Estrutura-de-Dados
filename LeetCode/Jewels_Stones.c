//LeetdCode -   771 -

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//eu preciso comparar a string joias com a pedras e ver quantas sao iguais
//Minisculas e Maiusculas são diferentes
//retornar um contador

int numJewelsInStones(char* jewels, char* stones);

int main(){
    char *p1 = "aA";
    char *p2 = "aAAbbbb";

    printf("O numero de repeticoes: %d\n\n", numJewelsInStones(p1,p2));

    return 0;
}

int numJewelsInStones(char* jewels, char* stones){
        int count = 0;
        
        
        for (int i = 0; i < strlen(stones); i++){
            
            for (int j = 0; j < strlen(jewels); j++)
            {
                if (stones[i] == jewels[j])
                {
                    count++;
                }
            }
        }
            return count;
    }