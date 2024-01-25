#include <stdio.h>

void all_minus(int pole[], int n){
    for (int i = 0; i < n; i++){
        pole[i] = -1;
    }   
}

void report(int p[], int n, int lb, int rb){
    int max_n = 7; //2*2*2-1
    int indexy[32];
    all_minus(indexy, 32);
    for (int a = 0; a < max_n; a++){
        all_minus(indexy, 32);
        for (int i = 0; i < 32; i++){
            if (a & (1 << i)){
                indexy[i] = 1;
            }
        }
        int x = 0;
        for (int i = 0; i < 32; i++){
            if (indexy[i]!=-1){
                x+=p[i];
            }
        }
        if ((lb<=x) && (x<=rb)){
            for (int i = 0; i < 32; i++){
                if (indexy[i]!=-1){
                    printf("%i ", p[i]);
                }
            }

        }
        printf("\n");
    }
    
}

void main(){
    int p[3] = {5, 3, 9};
    report(p, 3, 6, 13);
}