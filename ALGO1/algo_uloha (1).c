#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>

int insertion_sort_with_counting(int [], int, int);
int insertion_sort_ascending(int [], int);
int insertion_sort_descending(int [], int);

int quick_sort_with_counting(int [], int, int);
void quick_sort_ascending(int [], int, int, int []);
int partition_ascending(int [], int, int, int []);
void quick_sort_descending(int [], int, int, int []);
int partition_descending(int [], int, int, int []);

int merge_sort_with_counting(int [], int, int);
void merge_sort_ascending(int [], int, int, int []);
void merge_ascending(int [], int, int, int, int []);
void merge_sort_descending(int [], int, int, int []);
void merge_descending(int [], int, int, int, int []);

int check_if_sorted_asc(int A[], int i, int n){
    if (i>=n-1){
        return 1;
    }
    return ((A[i]<=A[i+1]) && check_if_sorted_asc(A, i+1, n));
}

int check_if_sorted_desc(int A[], int i, int n){
    if (i>=n-1){
        return 1;
    }
    return ((A[i]>=A[i+1]) && check_if_sorted_desc(A, i+1, n));
}


void vypis_vysledky(int pole[]){
  for (int i = 0; i < 10; i++){
    printf("%-12i", pole[i]);
  }
}

int main(){
  time_t t;
  int INSERTION[10], QUICK[10], MERGE[10];
  for (int z = 0; z < 10; z++){
    int A[10000], B[10000], C[10000];

    srand((unsigned) (time(&t)+z));
    for (int i = 0; i < 10000; i++){
      A[i] = 0 + rand() % INT_MAX;
      B[i] = A[i];
      C[i] = A[i];
    }

    INSERTION[z] = insertion_sort_with_counting(A, 10000, 1);
    QUICK[z] = quick_sort_with_counting(B, 10000, 1);
    MERGE[z] = merge_sort_with_counting(C, 10000, 1);
  }

  printf("\n\n");
  printf("%-16s|  ", "Insertion sort");
  vypis_vysledky(INSERTION);
  
  printf("\n");
  printf("%-16s|  ", "Quick sort");
  vypis_vysledky(QUICK);

  printf("\n");
  printf("%-16s|  ", "Merge sort");
  vypis_vysledky(MERGE);
  printf("\n\n");
  
  return 0;
}

int insertion_sort_ascending(int A[], int N){
    int t, j;
    int count = 0;
    for (int i = 1; i < N; i++){
        t = A[i];
        j = i-1;
        while ((j>=0) && (A[j]>t)){
            count++;
            A[j+1] = A[j];
            j--;
        }
        if (j>=0){ count++; }

        A[j+1] = t;
    }
    return count;
}

int insertion_sort_descending(int A[], int N){
    int t, j;
    int count = 0;
    for (int i = 1; i < N; i++){
        t = A[i];
        j = i-1;
        while ((j>=0) && (A[j]<t)){
            count++;
            A[j+1] = A[j];
            j--;
        }
        if (j>=0){ count++; }

        A[j+1] = t;
    }
    return count;
}

int insertion_sort_with_counting(int pole[], int velikost, int poradi){
    if (poradi<0){
        return insertion_sort_descending(pole, velikost);
    }
    return insertion_sort_ascending(pole, velikost);
}

int quick_sort_with_counting(int pole[], int velikost, int poradi){
    int count[1] = {0};
    if (poradi<0){
        quick_sort_descending(pole, 0, velikost-1, count);
        return count[0];
    }
    quick_sort_ascending(pole, 0, velikost-1, count);
    return count[0];
}

void quick_sort_ascending(int A[], int p, int r, int count[]){
  if (p<r){
    int q = partition_ascending(A, p, r, count);
    quick_sort_ascending(A, p, q-1, count);
    quick_sort_ascending(A, q+1, r, count);
  }
}

int partition_ascending(int A[], int p, int r, int count[]){
  int x = A[r];
  int i = p-1;
  int t;
  for (int j = p; j <= r-1; j++){
    if (A[j]<=x){
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
    count[0]++;
  }
  t = A[i+1];
  A[i+1] = A[r];
  A[r] = t;

  return i+1; 
}

void quick_sort_descending(int A[], int p, int r, int count[]){
  if (p<r){
    int q = partition_descending(A, p, r, count);
    quick_sort_descending(A, p, q-1, count);
    quick_sort_descending(A, q+1, r, count);
  }
}

int partition_descending(int A[], int p, int r, int count[]){
  int x = A[r];
  int i = p-1;
  int t;
  for (int j = p; j <= r-1; j++){
    if (A[j]>=x){
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
    count[0]++;
  }
  t = A[i+1];
  A[i+1] = A[r];
  A[r] = t;

  return i+1; 
}

int merge_sort_with_counting(int pole[], int velikost, int poradi){
    int count[1] = {0};
    if (poradi<0){
        merge_sort_descending(pole, 0, velikost-1, count);

        return count[0];
    }
    merge_sort_ascending(pole, 0, velikost-1, count);

    return count[0];
}

void merge_sort_ascending(int B[], int p, int r, int count[]){
  if (p<r){
    int q = floor((p+r)/2);
    merge_sort_ascending(B, p, q, count);
    merge_sort_ascending(B, q+1, r, count);
    merge_ascending(B, p, q, r, count);
  }
}

void merge_ascending(int B[], int p, int q, int r, int count[]){
  int n1 = q-p+1;
  int n2 = r-q;
  int L[n1+1];
  int R[n2+1];
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
    if ((L[i]!=INT_MAX) && (R[j]!=INT_MAX)){
      count[0]++;
    }

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

void merge_sort_descending(int B[], int p, int r, int count[]){
  if (p<r){
    int q = floor((p+r)/2);
    merge_sort_descending(B, p, q, count);
    merge_sort_descending(B, q+1, r, count);
    merge_descending(B, p, q, r, count);
  }
}

void merge_descending(int B[], int p, int q, int r, int count[]){
  int n1 = q-p+1;
  int n2 = r-q;
  int L[n1+1];
  int R[n2+1];
  for (int i = 0; i <= n1-1; i++){
    L[i] = B[p+i];
  }
  for (int j = 0; j <= n2-1; j++){
    R[j] = B[q+j+1];
  }
  L[n1] = INT_MIN;
  R[n2] = INT_MIN;

  int i = 0;
  int j = 0;

  for (int k = p; k <= r; k++){
    if ((L[i]!=INT_MIN) && (R[j]!=INT_MIN)){
      count[0]++;
    }  

    if (L[i]<=R[j]){
      B[k]=R[j];
      j++;
    }
    else{
      B[k]=L[i];
      i++;
    }
  }
}
