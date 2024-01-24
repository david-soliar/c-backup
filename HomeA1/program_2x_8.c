#include <stdio.h>

int main (){
    float a = 8;
    float b = 3;

    float sum = a+b;
    float diff1 = a-b;
    float diff2 = b-a;
    float prod = a*b;

    printf("Sucet je %g\nRozdiel je %g (alebo %g)\nSucin je %g", sum, diff1, diff2, prod);

    return 0;
}