#include <stdio.h>
#include <math.h>

typedef unsigned char byte;
void LPar(byte Z[],unsigned d);
unsigned TLPar(const byte Z[],unsigned d);
void OLPar(byte Z[],unsigned d);

void output(const byte Z[], unsigned d){
    for (int i = 0; i < (d-1); i++){
        printf("%x ", Z[i]);
    }
    
}

void main(){
    byte S[] = "ABCDEFG";
    /*01000001 01000010 01000011 01000100 01000101 01000110 01000111*/
    
    output(S, sizeof S);
    printf("\n%u\n", TLPar(S, sizeof S));
    
    LPar(S, sizeof S);
    
    output(S, sizeof S);
    printf("\n%u\n", TLPar(S, sizeof S));
    
    OLPar(S, sizeof S);
    
    output(S, sizeof S);
    printf("\n%u\n", TLPar(S, sizeof S));
}

unsigned TLPar(const byte Z[], unsigned d){
    int T[8];
    int Zx = 0;
    int s = 0;
    for (int i = 0; i < 8; i++){
        T[i] = (int) pow(2, i);
    }
    for (int i = 0; i < (d-1); i++){
        s = 0;
        for (int j = 0; j < (sizeof T/4); j++){
            if ((Z[i]&T[j])==T[j]){
                s++;
            }
        }
        if (s%2==0){
            Zx++;
        }
    }
    return Zx;
}

void LPar(byte Z[],unsigned d){
    int T[8];
    int s = 0;
    for (int i = 0; i < 8; i++){
        T[i] = (int) pow(2, i);
    }

    for (int i = 0; i < (d-1); i++){
        s = 0;
        for (int j = 0; j < (sizeof T/4); j++){
            if ((Z[i]&T[j])==T[j]){
                s++;
            }
        }
        if (s%2==0){
            Z[i] = Z[i]^(128);
        }
    }
}

void OLPar(byte Z[],unsigned d){
    for (int i = 0; i < (d-1); i++){
        if ((Z[i]&128)==128){
            Z[i] = Z[i]^128;   
        }
    }
}
