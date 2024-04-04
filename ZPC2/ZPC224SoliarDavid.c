#include <stdio.h>
#include "U24.inc"

char Vetsi(Datum a,Datum b){ 
    int ax = a.rok*12*32 + a.mesic*32 + a.den;
    int bx = b.rok*12*32 + b.mesic*32 + b.den;
    
    return ax>bx;
}

char Mensi(Datum a,Datum b){
    int ax = a.rok*12*32 + a.mesic*32 + a.den;
    int bx = b.rok*12*32 + b.mesic*32 + b.den;
    
    return ax<bx;
}

void Vypsat(const Datum D[], int n){
    for (int i = 0; i < n; i++){
        printf("%i.%i.%i  ", D[i].den, D[i].mesic, D[i].rok);
        if ((i+1)%5==0){
            printf("\n");
        }
    }
}

void Tridit(Datum D[], int n, char (*f)(Datum,Datum)){
  Datum t;
  for (int i = 0; i <= (n-2); i++){
    for (int j = (n-1); j >= (i+1); j--){
      if (f(D[j], D[j-1])){
        t = D[j];
        D[j] = D[j-1];
        D[j-1] = t;
      }
    }
  }
    
}

void main(){
    char (*vzostupne)(Datum, Datum) = Mensi;
    char (*zostupne)(Datum, Datum) = Vetsi;
    Tridit(D, POCET, zostupne);
    //Tridit(D, POCET, vzostupne);
    Vypsat(D, POCET);
}

