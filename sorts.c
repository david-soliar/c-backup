#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output(int [], int, char *);
void insertion_sort(int [], int);
void selection_sort(int [], int);

int main(){
  int n = 20;
  int A[n];
  for(int i=0; i<n; i++){
    A[i]=rand()%100;
  }
  output(A, n, "original array");
  printf("\n");

  insertion_sort(A, n);
  selection_sort(A, n);
  return 0;
}

void output(int A[], int n, char *algo_name){
  printf("%s: ", algo_name);
  for(int i=0; i<n; i++){
    printf("%i ", A[i]);
  }
  printf("\n");
}

void insertion_sort(int B[], int n){
  int A[n];
  memcpy(A, B, n*sizeof(int));

  int t, j;
  for (int i = 1; i < n; i++){
    t = A[i];
    j = i-1;
    while ((j>=0) && (A[j]>t)){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = t; /*tu je +1 lebo pokial sa dostane az na koniec tak j=-1 preto treba dat na 0 a pokial to skonci vo while tak podmienka neplati ale j sa zmensilo o 1*/
  }

  output(A, n, "insertion sort");
}

void selection_sort(int B[], int n){
  int A[n];
  memcpy(A, B, n*sizeof(int));

  int A_min, t;

  for (int i = 0; i < (n-1); i++){
    A_min = i;
    
    for (int j = (i+1); j < n; j++){
      if (A[j] < A[A_min]){
        A_min = j;
      }
    }
    t = A[i];
    A[i] = A[A_min];
    A[A_min] = t;
  }
  output(A, n, "selection sort");
}