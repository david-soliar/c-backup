#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define N 20

void output(int [], char *);

void insertion_sort(int []);

void selection_sort(int []);

void bubble_sort(int []);

void optimized_bubble_sort(int []);

void cocktail_sort(int []);

void quick_sort_init(int []);
void quick_sort(int [], int, int);
int partition(int [], int, int);

void merge_sort_init(int []);
void merge_sort(int [], int, int);
void merge(int [], int, int, int);

int parent(int);
int left(int);
int right(int);
void max_heapify(int [], int);
void build_max_heap(int []);
void heap_sort(int []);

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
  cocktail_sort(A);
  quick_sort_init(A);
  merge_sort_init(A);
  heap_sort(A);
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

void cocktail_sort(int B[]){
  int A[N];
  memcpy(A, B, N*sizeof(int));
  int p = 0;
  int q = N-1;
  int t;
  while (abs(q-p)>1){
    for (int j = q; j > p; j--){
      if (A[j] < A[j-1]){
        t = A[j];
        A[j] = A[j-1];
        A[j-1] = t;
      }
    }
    p++;
    for (int j = p; j < q; j++){
      if (A[j] > A[j+1]){
        t = A[j];
        A[j] = A[j+1];
        A[j+1] = t;
      }
    }
    q--;
  }
  output(A, "cocktail sort");
}

void quick_sort_init(int B[]){
  int A[N];
  memcpy(A, B, N*sizeof(int));

  quick_sort(A, 0, N-1);
  output(A, "quick sort");
}

void quick_sort(int B[], int p, int r){
  if (p<r){
    int q = partition(B, p, r);
    quick_sort(B, p, q-1);
    quick_sort(B, q+1, r);
  }
}

int partition(int B[], int p, int r){
  int x = B[r];
  int i = p-1;
  int t;
  for (int j = p; j <= r-1; j++){
    if (B[j]<=x){
      i++;
      t = B[i];
      B[i] = B[j];
      B[j] = t;
    }
  }
  t = B[i+1];
  B[i+1] = B[r];
  B[r] = t;

  return i+1; 
}

void merge_sort_init(int B[]){
  int A[N];
  memcpy(A, B, N*sizeof(int));

  merge_sort(A, 0, N-1);
  output(A, "merge sort");
}

void merge_sort(int B[], int p, int r){
  if (p<r){
    int q = floor((p+r)/2);
    merge_sort(B, p, q);
    merge_sort(B, q+1, r);
    merge(B, p, q, r);
  }
}

void merge(int B[], int p, int q, int r){
  int n1 = q-p+1;
  int n2 = r-q;
  int L[N]; //n1+1
  int R[N]; //n2+1
  for (int i = 0; i <= n1-1; i++){
    L[i] = B[p+i];
  }
  for (int j = 0; j <= n2-1; j++){
    R[j] = B[q+j+1];
  }
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  int i = 0;
  int j = 0;

  for (int k = p; k <= r; k++){
    if (L[i]<=R[j]){
      B[k]=L[i];
      i++;
    }
    else{
      B[k]=R[j];
      j++;
    }
  }
}

int heap_size;

int parent(int i){
  return (i-1)/2;
}

int left(int i){
  return 2*i + 1;
}

int right(int i){
  return 2*i + 2;
}

void max_heapify(int B[], int i){
  int l = left(i);
  int r = right(i);
  int largest;

  if ((l<=heap_size) && (B[l]>B[i])){
    largest = l;
  }
  else{
    largest = i;
  }

  if ((r<=heap_size) && (B[r]>B[largest])){
    largest = r;
  }

  if (largest != i){
    int t = B[largest];
    B[largest] = B[i];
    B[i] = t;
    
    max_heapify(B, largest);
  }
}

void build_max_heap(int B[]){
  heap_size = N-1; //tu musi byt N-1 alebo porovnania v heapify musia byt bez rovna sa pri heapsize
  for (int i = N/2-1; i >= 0; i--){
    max_heapify(B, i);
  }
}

void heap_sort(int B[]){
  int A[N];
  memcpy(A, B, N*sizeof(int));
  
  build_max_heap(A);
  for (int i = (N-1); i >= 1; i--){
    int t = A[0];
    A[0] = A[i];
    A[i] = t;
    heap_size--;
    max_heapify(A, 0);
  }
  
  output(A, "heap sort");
}