#include <stdio.h> //vystup print
#include <stdlib.h> //random
#include <math.h> //floor
#include <string.h> //memcpy TOTO TREBA SPRAVIT INAK TO KOPIROVANIE LISTOV lebo zbytocne tu mam tu lib
#include <limits.h> //int_max a min AJ TOTO MOZEM RADSEJ SPRAVIT RUCNE namiesto const
#include <time.h> // random cisla

#define VELIKOST 10000
#define CISLA_OD 0 //-100
#define CISLA_DO 10000000

void napln_pole(int pole[]);
void vypis_pole(int pole[]);

void output(int [], char *);

int insertion_sort_with_counting(int [], int, int);
int insertion_sort_max(int [], int, int);
int insertion_sort_min(int [], int, int);

int quick_sort_with_counting(int [], int, int);
void quick_sort_max(int [], int, int, int []);
int partition_max(int [], int, int, int []);
void quick_sort_min(int [], int, int, int []);
int partition_min(int [], int, int, int []);

int merge_sort_with_counting(int [], int, int);
void merge_sort_max(int [], int, int, int []);
void merge_max(int [], int, int, int, int []);
void merge_sort_min(int [], int, int, int []);
void merge_min(int [], int, int, int, int []);

int check_if_sorted_asc(int A[], int i){
    if (i>=VELIKOST-1){
        return 1;
    }
    
    return ((A[i]<=A[i+1]) && check_if_sorted_asc(A, i+1));
}

int check_if_sorted_desc(int A[], int i){
    if (i>=VELIKOST-1){
        return 1;
    }
    
    return ((A[i]>=A[i+1]) && check_if_sorted_desc(A, i+1));
}

int main(){
    /*
        for (int i = 0; i < 10; i++){
        int A[VELIKOST];
        napln_pole(A);
        printf("insertion max %i\n", insertion_sort_with_counting(A, VELIKOST, 1));
        printf("insertion min %i\n", insertion_sort_with_counting(A, VELIKOST, -2));
        //quick_sort_with_counting(A, VELIKOST, 1);
        //merge_sort_with_counting(A, VELIKOST, 1);
    }
    */

    int A[VELIKOST];
    napln_pole(A);
    printf(" insertion sort %i\n", insertion_sort_with_counting(A, VELIKOST, 1));
    printf(" quick sort %i\n", quick_sort_with_counting(A, VELIKOST, 1));
    printf(" merge sort %i\n", merge_sort_with_counting(A, VELIKOST, 1));
    return 0;
}

int insertion_sort_max(int A[], int N, int count){
    int t, j;
    for (int i = 1; i < N; i++){
        t = A[i];
        j = i-1;
        while ((j>=0) && (A[j]>t)){
            count++;
            A[j+1] = A[j];
            j--;
        }
        //count++;
        if (j>=0){ count++; }
        // lebo ak to uz ide koncit a prva podmienka plati tak checkne druhu 
        // ALE ZALEZI CI POUZIVA SKRATENE VYHODNOCOVANIE ak nie tak staci iba ten riadok nad tymto 
        // ak vyuziva tak musi tu byt toto if a ten riadok hore musi ist prec
        // yo vyuziva to takze to treba
        
        A[j+1] = t;
    }
    printf("%i:  ", check_if_sorted_asc(A, 0));
    //vypis_pole(A);
    return count;
}

int insertion_sort_min(int A[], int N, int count){
    int t, j;
    for (int i = 1; i < N; i++){
        t = A[i];
        j = i-1;
        while ((j>=0) && (A[j]<t)){
            count++;
            A[j+1] = A[j];
            j--;
        }
        //count++;
        if (j>=0){ count++; }
        //to iste teda plati aj tu
        A[j+1] = t;
    }
    printf("%i:  ", check_if_sorted_desc(A, 0));
    //vypis_pole(A);
    return count;
}

int insertion_sort_with_counting(int pole[], int velikost, int poradi){
    int A[VELIKOST];
    memcpy(A, pole, velikost*sizeof(int));

    if (poradi<0){
        return insertion_sort_min(A, velikost, 0);
    }
    return insertion_sort_max(A, velikost, 0);
}

int quick_sort_with_counting(int pole[], int velikost, int poradi){
    int A[VELIKOST];
    memcpy(A, pole, velikost*sizeof(int));

    int count[1] = {0};
    if (poradi<0){
        quick_sort_min(A, 0, velikost-1, count);
        printf("%i:  ", check_if_sorted_desc(A, 0));
        //vypis_pole(A);
        return count[0];
    }
    quick_sort_max(A, 0, velikost-1, count);
    printf("%i:  ", check_if_sorted_asc(A, 0));
    //vypis_pole(A);
    return count[0];
}

void quick_sort_max(int A[], int p, int r, int count[]){
  if (p<r){
    int q = partition_max(A, p, r, count);
    quick_sort_max(A, p, q-1, count);
    quick_sort_max(A, q+1, r, count);
  }
}

int partition_max(int A[], int p, int r, int count[]){
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

void quick_sort_min(int A[], int p, int r, int count[]){
  if (p<r){
    int q = partition_min(A, p, r, count);
    quick_sort_min(A, p, q-1, count);
    quick_sort_min(A, q+1, r, count);
  }
}

int partition_min(int A[], int p, int r, int count[]){
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
    int A[VELIKOST];
    memcpy(A, pole, velikost*sizeof(int));

    int count[1] = {0};
    if (poradi<0){
        merge_sort_min(A, 0, velikost-1, count);
        printf("%i:  ", check_if_sorted_desc(A, 0));
        //vypis_pole(A);
        return count[0];
    }
    merge_sort_max(A, 0, velikost-1, count);
    printf("%i:  ", check_if_sorted_asc(A, 0));
    //vypis_pole(A);
    return count[0];
}

void merge_sort_max(int B[], int p, int r, int count[]){
  if (p<r){
    int q = floor((p+r)/2);
    merge_sort_max(B, p, q, count);
    merge_sort_max(B, q+1, r, count);
    merge_max(B, p, q, r, count);
  }
}

void merge_max(int B[], int p, int q, int r, int count[]){
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
    if (L[i]<=R[j]){
      B[k]=L[i];
      i++;
    }
    else{
      B[k]=R[j];
      j++;
    }
    count[0]++;
  }
}

void merge_sort_min(int B[], int p, int r, int count[]){
  if (p<r){
    int q = floor((p+r)/2);
    merge_sort_min(B, p, q, count);
    merge_sort_min(B, q+1, r, count);
    merge_min(B, p, q, r, count);
  }
}

void merge_min(int B[], int p, int q, int r, int count[]){
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
    if (L[i]<=R[j]){
      B[k]=R[j];
      j++;
    }
    else{
      B[k]=L[i];
      i++;
    }
    count[0]++;
  }
}

void napln_pole(int pole[]){
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < VELIKOST; i++){
      pole[i] = CISLA_OD + rand() % CISLA_DO;  
    }
}

void vypis_pole(int pole[]){
    for (int i  =  0; i < VELIKOST; i++){
        printf("%d, ", pole[i]);
    }
}
