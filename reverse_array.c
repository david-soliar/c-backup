#include <stdio.h>
#include <math.h>

void reverse_array(int A[], int n){
    int t;
    for(int i = 0; i<floor(n/2); i++){
        t = A[i];
        A[i] = A[n-1-i];
        A[n-1-i] = t;
    }
}

int main() {
    //nt A[] = {1,2,3,4,5,6,7};
    //int A[] = {1,2,3,4,5,6,7,8};
    int A[] = {1,2,3,4,5,6,7,8,9};
    int n = (sizeof A)/4;
    
    reverse_array(A, n);
    
    for(int i = 0; i<n; i++){
        printf("%i ", A[i]);
    }
    
    return 0;
}