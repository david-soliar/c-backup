#include <stdio.h>

int main(void){
    int a;
    printf("napis cislo 2-5: ");
    scanf("%i", &a);
    switch (a){
    case 2:
        printf("cislo %i na druhu je %i",a, a*a);
        break;
    case 3:
        printf("cislo %i na druhu je %i",a, a*a);
        break;
    case 4:
        printf("cislo %i na druhu je %i",a, a*a);
        break;
    case 5:
        printf("cislo %i na druhu je %i",a, a*a);
        break;
    default:
        printf("cislo %i nie je z rozsahu 2-5", a);
        break;
    }
}