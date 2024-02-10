#include <stdio.h>
#include <ctype.h>
#include "U03.inc"

int main(void){
    int pocet_pismen[POCET];

    for (int i = 0; i < POCET; i++){
        pocet_pismen[i] = 0;
        for (int j = 0; j < (sizeof T/sizeof T[0] -1); j++){
            if (S[i]==toupper(T[j])){
                pocet_pismen[i] += 1;
            }
        }
        printf("%c-%i", S[i], pocet_pismen[i]);
        ((i+1)%5) ? printf(" ") : printf("\n");
    }
}
