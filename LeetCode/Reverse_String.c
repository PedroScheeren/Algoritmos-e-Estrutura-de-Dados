// LeetCode - 344 -
#include <stdio.h>
#include <string.h>


void reverseString(char* s, int sSize);

int main(){

    char s[] ="Hello";
    int sSize = strlen(s);

    reverseString(s,sSize);

    return 0;
}

void reverseString(char* s, int sSize){

    for (int i=sSize-1; i >= 0; i--){
        printf("%c ",s[i]);
    }

    printf("\n");

}