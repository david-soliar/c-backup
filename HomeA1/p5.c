#include <stdio.h>

int main(){
    int a = 0;
    int b = 1;
    int c = 0;

    for (int i = 0; i < 30; i++){
        printf("%i.) %i\n", i, a);
        c = b+a;
        a = b;
        b = c;

    }
    
}