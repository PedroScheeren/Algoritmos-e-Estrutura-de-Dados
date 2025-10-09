#include <stdio.h>
#include <string.h>

char confere_sub_string(char *str, char *sub);


int main(){
    char texto[]= "Ola mundo";
    char sub[]= "..";

    if (confere_sub_string(texto,sub))
        printf("Contém\n\n");
    else
        printf("Não contém\n\n");
    
    



    return 0;
}

char confere_sub_string(char *str, char *sub){
    if (strstr(str,sub))
    {
        return 1;
    }
    
    return 0;
}