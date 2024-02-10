#include <stdio.h>

void main(){
    int u;
    int v = 3;
    printf("zadaj cele cislo vacsie ako 1: ");
    scanf("%i", &u);
    if (u<=1){
        printf("\ncislo nie je vacsie ako 1");
        return;
    }
    while ((u%2)==0){
        printf("2 ");
        u = u/2;
    }
    while (v<=u){
        if ((u%v)==0){
            printf("%i ", v);
            u = u/v;
        }
        else{
            v += 2;
        }
    }
}