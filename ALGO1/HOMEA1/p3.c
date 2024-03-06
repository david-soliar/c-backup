#include <stdio.h>

int main(void){
    int a;
    printf("napis cislo 2-5: ");
    scanf("%i", &a);

    if (a==2) printf("cislo %i na druhu je %i",a, a*a);
    else if (a==3) printf("cislo %i na druhu je %i",a, a*a);
    else if (a==4) printf("cislo %i na druhu je %i",a, a*a);
    else if (a==5) printf("cislo %i na druhu je %i",a, a*a);
    else printf("cislo %i nie je z 2-5",a);
}