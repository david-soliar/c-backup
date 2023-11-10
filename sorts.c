#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

void output(int [], char *);
void insertion_sort(int []);
void selection_sort(int []);
void bubble_sort(int []);
void optimized_bubble_sort(int []);

int main(){
  int A[N];
  for(int i=0; i<N; i++){
    A[i]=rand()%100;
  }
  output(A, "original array");
  printf("\n");

  insertion_sort(A);
  selection_sort(A);
  bubble_sort(A);
  optimized_bubble_sort(A);
  return 0;
}

void output(int A[], char *algo_name){
  printf("%-*s: ", 32, algo_name);
  for(int i=0; i<N; i++){
    printf("%i ", A[i]);
  }
  printf("\n");
}

void insertion_sort(int B[]){
  int A[N];
  memcpy(A, B, N*sizeof(int));

  int t, j;
  for (int i = 1; i < N; i++){
    t = A[i];
    j = i-1;
    while ((j>=0) && (A[j]>t)){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = t; /*tu je +1 lebo pokial sa dostane az na koniec tak j=-1 preto treba dat na 0 a pokial to skonci vo while tak podmienka neplati ale j sa zmensilo o 1*/
  }

  output(A, "insertion sort");
}

void selection_sort(int B[]){
  int A[N];
  memcpy(A, B, N*sizeof(int));

  int A_min, t;

  for (int i = 0; i < (N-1); i++){
    A_min = i;
    
    for (int j = (i+1); j < N; j++){
      if (A[j] < A[A_min]){
        A_min = j;
      }
    }
    t = A[i];
    A[i] = A[A_min];
    A[A_min] = t;
  }
  output(A, "selection sort");
}
//najlepsia a najhorsia je obidvoje n**2

void bubble_sort(int B[]){
  int A[N];
  memcpy(A, B, N*sizeof(int));

  int t;
  for (int i = 0; i <= (N-2); i++){
    for (int j = (N-1); j >= (i+1); j--){
      if (A[j] < A[j-1]){
        t = A[j];
        A[j] = A[j-1];
        A[j-1] = t;
      }
    }
  }
  output(A, "bubble sort");
}
//najlepsia a najhorsia je obidvoje n**2

void optimized_bubble_sort(int B[]){
  int A[N];
  memcpy(A, B, N*sizeof(int));

  int t;
  int s;
  for (int i = 0; i < (N-1); i++){
    for (int j = (N-1); j > (N-s); j--){
      if (A[j] < A[j-1]){
        t = A[j];
        A[j] = A[j-1];
        A[j-1] = t;
        s = j;
      }
    }
    if (s==(N-1)){
      printf("%i ", i);
      break;
  }
}
output(A, "optimized bubble sort");}