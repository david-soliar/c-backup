#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define x 20

void output(int [], int, char *);
void nth_bigest_int(int []);
void third_bigest_int(int []);

int main(){
  int A[20];
  for(int i=0; i<20; i++){
    A[i]=rand()%100;
  }
  output(A, 20, "original array");
  printf("\n");

  third_bigest_int(A);
  nth_bigest_int(A);
  return 0;
}

void output(int A[], int n, char *algo_name){
  printf("%s: ", algo_name);
  for(int i=0; i<n; i++){
    printf("%i ", A[i]);
  }
  printf("\n");
}

void third_bigest_int(int A[]){
  int X[3] = {0};
  for (int i = 0; i < 20; i++){
    if (A[i]>X[2]){
      X[0] = X[1];
      X[1] = X[2];
      X[2] = A[i];
      break;
    }
    else if (A[i]>X[1]){
      X[0] = X[1];
      X[1] = A[i];
      break;
    }
    else if (A[i]>X[0]){
      X[0] = A[i];
      break;
    }
  }
  printf("\n3tie najvacsie je %i\n", X[2]);
}

void nth_bigest_int(int A[]){
  int X[x] = {0};
  for (int i = 0; i < 20; i++){
    for (int j = (x-1); j >= 0; j--){
      if (A[i]>X[j]){
        for (int k = 0; k < j; k++){
          X[k] = X[k+1];
        }
        X[j] = A[i];
        break;
      }
    }
  }
  for (int i = 0; i < x; i++){
    printf("%i ", X[i]);
  }
  printf("\n%i najvacsie cislo je: %i", x, X[0]);
}
