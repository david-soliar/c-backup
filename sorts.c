#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

void output(int [], char *);
void insertion_sort(int []);
void selection_sort(int []);
void bubble_sort(int []);
void optimized_bubble_sort(int []);
void continuous_set_sort(int []);

int main(){
  int A[N];
  for(int i=0; i<N; i++){
    A[i]=rand()%100;
  }

  int X[] = {4, 9, 16, 17, 13, 10, 6, 12, 5, 15, 7, 3, 8, 21, 18, 22, 20, 19, 14, 11};
  continuous_set_sort(X);

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

  int s, t;
  int x = 0;
  for (int i = 0; i < (N-2); i++){
    for (int j = (N-1); j > x; j--){
      if (A[j] < A[j-1]){
        t = A[j];
        A[j] = A[j-1];
        A[j-1] = t;
        s = j;
      }
    }
    if (s==x){
      break;
    }
    x = s; //musim pouzit aj x lebo keby s je v podmienke for cyklu tak to berie vzdy to nove s a to je fail
  }
  output(A, "optimized bubble sort");
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