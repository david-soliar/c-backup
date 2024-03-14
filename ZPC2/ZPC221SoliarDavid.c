#include <stdio.h>
#include "U21.inc"

void main(){
    Mnozina C;
    C.pocet = 0;
    Operace k = SJEDNOCENI;
    operace(k, &A, &B, &C);
    vypis(&C, 5);
}

void operace(Operace O,const Mnozina *A,const Mnozina *B,Mnozina *C){
    if(O!=1){//sjednoceni
        for (int i = 0; i < (*A).pocet; i++){
            char a = (*A).Z[i];
            int s = 0;
            for (int j = 0; j < (*C).pocet; j++){
                char c = (*C).Z[j];
                if (a == c){
                    s++;
                }
            }
            if (s==0){
                (*C).Z[(*C).pocet] = a;
                (*C).pocet++;
            }
        }
        for (int i = 0; i < (*B).pocet; i++){
            char b = (*B).Z[i];
            int s = 0;
            for (int j = 0; j < (*C).pocet; j++){
                char c = (*C).Z[j];
                if (b == c){
                    s++;
                }
            }
            if (s==0){
                (*C).Z[(*C).pocet] = b;
                (*C).pocet++;
            }
        }
    }
    else{//prunik
        for (int i = 0; i < (*A).pocet; i++){
            char a = (*A).Z[i];
            for (int j = 0; j < (*B).pocet; j++){
                char b = (*B).Z[j];
                if (a == b){
                    (*C).Z[(*C).pocet] = a;
                    (*C).pocet++;
                }
            }
        }   
    }
}

void vypis(const Mnozina *M, int n){
    for (int i = 0; i < (*M).pocet; i++){
        printf("%c  ", (*M).Z[i]);
        if (0==(i+1)%n){
            printf("\n");
        }
    }
}
