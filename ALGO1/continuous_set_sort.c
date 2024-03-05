#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

void output(int [], char *);

void continuous_set_sort(int []);

int main(){
  int A[N];
  for(int i=0; i<N; i++){
    A[i]=rand()%100;
  }

  int X[] = {4, 9, 16, 17, 13, 10, 6, 12, 5, 15, 7, 3, 8, 21, 18, 22, 20, 19, 14, 11};
  continuous_set_sort(X);

  return 0;
}

void output(int A[], char *algo_name){
  printf("%-*s: ", 32, algo_name);
  for(int i=0; i<N; i++){
    printf("%i ", A[i]);
  }
  printf("\n");
}

void continuous_set_sort(int B[]){
  int A[N];
  memcpy(A, B, N*sizeof(int));
  
  int t = A[N-1];
  for (int i = 0; i < (N-1); i++){
    if (A[i]<t){
      t = A[i];
    }
  }//toto najde najmensi prvok
  
  for (int i = 0; i < N; i++){
    A[i] = A[i] - t;
  }
  
  int final_A[N];
  for (int i = 0; i < N; i++){
    final_A[A[i]] = B[i];
  }
  //primerny pripad je cca 11n+2
  //lepsi ako quicksort pre c = 1 a n0 = 2**11 teda n zacina na 2**12

  output(B, "original for continuous set sort");
  output(final_A, "continuous set sort");
  printf("\n");
  printf("\n");
}
