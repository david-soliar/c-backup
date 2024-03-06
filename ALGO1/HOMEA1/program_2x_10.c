#include <stdio.h>

int main(){
    int c = 398;

    printf("prva je %i\nposledna je %i", (c/100)%10, c%10);
    return 0;
}