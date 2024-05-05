#include <stdio.h>

#define Trideni(J,T) void J(T A[],int n){\
    for (int i = 0; i <= (n-2); i++){\
        for (int j = (n-1); j >= (i+1); j--){\
            if (A[j] < A[j-1]){\
                T t = A[j];\
                A[j] = A[j-1];\
                A[j-1] = t;\
            }\
        }\
    }\
}

#define Median(J,T,JT,S) S J(T A[],int n){\
    JT(A, n);\
    S x = (0==(n%2) ? (((S)A[n/2-1] + (S)A[n/2])/2) : A[n/2]);\
    return x;\
}

Trideni(TShort,short)
Median(MShort,short,TShort,float)
Trideni(TUChar,unsigned char)
Median(MUChar,unsigned char,TUChar,float)

void main(){
    short S[]={5,9,2,4,3};
    printf("%g\n", MShort(S,5));

    unsigned char U[]={5,9,1,8,4,3};
    printf("%g", MUChar(U,6));
}
