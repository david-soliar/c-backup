#include <stdio.h>
#include <math.h>
#include "U23.inc"

void Vypis(int []);

int not_in_array(int V[], int a){
    int d = V[0];
    for (int x = 1; x < d+1; x++){
        if (a==V[x]){
            return 0;
        }
    }
    return 1;
}

void main(){
    int V[200];
    V[0] = 0;
    Vyber(A, DELKA, ZAPORNA, V);
    Vypis(V);
}

void Vyber(const int *A[], unsigned dlzka, Typ c, int V[]){
    for (int i = 0; i < dlzka; i++){
        int d = A[i][0];
        for (int j = 1; j < d+1; j++){
            int a = A[i][j];
            switch (c){
                case 0:     
                    if (not_in_array(V, a)){
                        V[0]++;
                        V[V[0]] = a;
                    }
                    break;
                case 1:     
                    if (a>0 && not_in_array(V, a)){
                        V[0]++;
                        V[V[0]] = a;
                    }
                    break;
                case 2:     
                    if (a>=0 && not_in_array(V, a)){
                        V[0]++;
                        V[V[0]] = a;
                    }
                    break;
                case 3:     
                    if (a<0 && not_in_array(V, a)){
                        V[0]++;
                        V[V[0]] = a;
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

void Vypis(int V[]){
    int d = V[0];
    for (int i = 1; i < d+1; i++){
        printf("%i ", V[i]);
        if (i%10==0){
            printf("\n");
        }
    }
}
