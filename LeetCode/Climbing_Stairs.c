//LeetCode - 70 - 

#include <stdio.h>

int climbStairs(int n);

int main(){
    int n = 5;
    printf("Número de formas de subir %d degraus: %d\n", n, climbStairs(n));
    return 0;
}

int climbStairs(int n){
    if (n <= 2)
        return n;

    int a = 1, b = 2, c;

    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}
