#include <stdio.h>




int main(){

    int v_int=10, *p_int;
    float v_float=10.5, *p_float;
    char v_char='a', *p_char;

    printf("Antes de mudar:\n%d %f %c", v_int, v_float, v_char);

    p_int = &v_int;
    p_float = &v_float;
    p_char = &v_char;

    *p_int = 20;
    *p_float = 20.5;
    *p_char = 'P';
    printf("\nApos mudar:\n%d %f %c\n\n", v_int, v_float, v_char);


    return 0;
}