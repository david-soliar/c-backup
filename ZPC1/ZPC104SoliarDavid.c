#include <stdio.h>
#include <stdlib.h>

#define aa (sizeof A/sizeof *A)
#define bb (sizeof B/sizeof *B)

int prunik(const int A[],int a,const int B[],int b,int C[]);

int srozdil(const int A[],int a,const int B[],int b,int C[]);

int sjednoceni(const int A[],int a,const int B[],int b,int C[]);

int rozdil(const int A[],int a,const int B[],int b,int C[]);

void vypis(const int A[],int a,int n);

void main(){
    const int A[]={1,5,6,9,0,8,3};
    const int B[]={9,2,4,3,6,7};
    int C[aa + bb];

    printf("A:\n");
    vypis(A, aa, 5);

    printf("B:\n");
    vypis(B, bb, 5);

    printf("prunik:\n");
    vypis(C, prunik(A, aa, B, bb, C), 5);

    printf("srozdil:\n");
    vypis(C, srozdil(A, aa, B, bb, C), 5);

    printf("sjednoceni:\n");
    vypis(C, sjednoceni(A, aa, B, bb, C), 5);

    printf("rozdil:\n");
    vypis(C, rozdil(A, aa, B, bb, C), 5);
}

int prunik(const int A[],int a,const int B[],int b,int C[]){
    int x = 0;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            if (A[i]==B[j]){
                C[x] = A[i];
                x++;
            }
        }
    }
    return x;
}

int srozdil(const int A[],int a,const int B[],int b,int C[]){
    int x = 0;
    for (int i = 0; i < a; i++){
        int b_x = 0;
        for (int j = 0; j < b; j++){
            if (A[i]!=B[j]){
                b_x++;
            }
        }
        if (b_x==b){
            C[x] = A[i];
            x++;
        }
        
    }
    for (int i = 0; i < b; i++){
        int a_x = 0;
        for (int j = 0; j < a; j++){
            if (A[j]!=B[i]){
                a_x++;
            }
        }
        if (a_x==a){
            C[x] = B[i];
            x++;
        }
        
    }
    return x;
}

int sjednoceni(const int A[],int a,const int B[],int b,int C[]){
    int x = 0;
    for (int i = 0; i < a; i++){
        C[i] = A[i];
    }
    x += a;

    for (int j = 0; j < b; j++){
        int s = 0;
        for (int i = 0; i < x; i++){
            if (C[i]!=B[j]){
                s++;
            }
        }
        if (s==x){
            C[x] = B[j];
            x++;
        }
        
    }
    return x;
}

int rozdil(const int A[],int a,const int B[],int b,int C[]){
    int x = 0;
    for (int i = 0; i < a; i++){
        int b_x = 0;
        for (int j = 0; j < b; j++){
            if (A[i]!=B[j]){
                b_x++;
            }
        }
        if (b_x==b){
            C[x] = A[i];
            x++;
        }
    }
    return x;
}

void vypis(const int A[],int a,int n){
    for (int i = 0; i < a; i++){
        printf("%i ", A[i]);
        if ((i+1)==n){
            printf("\n");
        }
    }
    printf("\n");
}
