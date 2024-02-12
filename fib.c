#include <stdio.h>

int fib(int a, int b, int n){
    if (n==0){ return a; }
    if (n==1){ return b; }
    
    return fib(b, a+b, n-1);
}

void main(){
    int n;
    printf("zadaj index: ");
    scanf("%i", &n);
    printf("%i", fib(0, 1, n));
}

/*

T(0) = 1
T(1) = 1+1
T(n) = 1+1 + 2 + T(n-1)
T(n) = 4*(n-1) + 2
T(n) = 4*n - 2

*/