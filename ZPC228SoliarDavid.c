#include <stdio.h>
#include <string.h>

typedef enum {MUZ=1, ZENA} Pohlavi;
typedef struct  { char j[12]; Pohlavi p; } Jmeno;

void add_if_not_in(Jmeno J[], char to_add_str[], Pohlavi to_add_p, int n){
    for (int i = 0; i < n; i++){
        if (strcmp(J[i].j, to_add_str)==0){
            return;
        }
    }
    memcpy(J[n].j, to_add_str, strlen(to_add_str)+1);
    J[n].p = to_add_p;
    return;
}

void bubble_sort(Jmeno J[], int n){
    Jmeno t;
    for (int i = 0; i <= (n-2); i++){
        for (int j = (n-1); j >= (i+1); j--){
            if (strcmp(J[j].j, J[j-1].j)<0){
                t = J[j];
                J[j] = J[j-1];
                J[j-1] = t;
            }
        }
    }
    return;
}

void main(){
    Jmeno J[134];
    FILE *F=fopen("Jmena","rb");

    char l;
    char new;

    char to_add_str[12];
    Pohlavi to_add_p;
    
    int n = 0;
    while (1) {
        if (fscanf(F,"%c",&l)==EOF) {
                break;
        }

        if (l>50){ l -= 50; to_add_p = ZENA; }
        else { to_add_p = MUZ; }
        
        for (int i = 0; i < l; i++){
            if (fscanf(F,"%c",&new)==EOF) {
                break;
            }
            to_add_str[i] = new;
        }
        to_add_str[l] = '\0';
        
        add_if_not_in(J, to_add_str, to_add_p, n);
        n++;
    }

    bubble_sort(J, n);
    
    int x = 0;
    for (int i = 0; i < n; i++){
        if (J[i].p==ZENA){
            printf("%s ", J[i].j);
            x++;
            if (x%10==0){
                printf("\n");
            }
        }
    }

    printf("\n\n");
    x = 0;

    for (int i = 0; i < n; i++){
        if (J[i].p==MUZ){
            printf("%s ", J[i].j);
            x++;
            if (x%10==0){
                printf("\n");
            }
        }
    }
    fclose(F);
    return;
}