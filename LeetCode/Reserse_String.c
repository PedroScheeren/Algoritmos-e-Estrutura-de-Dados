//LeetCode - 344 -

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char* s, int sSize);

int main(){




    return 0;
}

void reverseString(char* s, int sSize){
    int left = 0;
    int rigth = sSize-1;

    while (left < rigth)
    {
        char temp = s[left];
        s[left] = s[rigth];
        s[rigth] = temp;
        left++;
        rigth--;
    }
    

}
