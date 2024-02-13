#include <stdio.h>
#include <string.h>
typedef struct {char cesky[16], anglicky[16];} Slovnik;
#include "U06.inc"

unsigned Vytvorit(const Slovnik vstupni[],unsigned pocet, Slovnik vystupni[]){
    int n = 0;
    int p = 0;
    int k = 1;
    strcpy(vystupni[0].cesky, vstupni[0].cesky);
    strcpy(vystupni[0].anglicky, vstupni[0].anglicky);
    for (int i = 1; i < pocet; i++){
        for (int j = 0; j < k; j++){
            int a = strcmp(vstupni[i].cesky, vystupni[j].cesky);
            int b = strcmp(vstupni[i].anglicky, vystupni[j].anglicky);
            if ((a==0) & (b==0)){
                n = 1;
                break;
            }
        }
        if (n==0){
            /*strcpy(vystupni[k].cesky, vstupni[i].cesky);
            strcpy(vystupni[k].anglicky, vstupni[i].anglicky);*/
            vystupni[k] = vstupni[i];

            p++;
            k++;
        }
        n = 0;
    }
    return p;
}

void Prelozit(const Slovnik S[],unsigned pocet, const char *cesky){
    int  x = 0;
    for (int i = 0; i < pocet; i++){
        if (strcmp(S[i].cesky, cesky)!=0){
            x++;
        }   
    }

    if (x==pocet){
        printf("\"%s\" nie je v slovniku");
        return;
    }
    
    
    printf("%s: ", cesky);
    for (int i = 0; i < pocet; i++){
        if (strcmp(cesky, S[i].cesky)==0){
            printf("%s ", S[i].anglicky);
        }
    }
    
}

void main(){
    int p;
    Slovnik S[CAPOCET];
    p = Vytvorit(CA, CAPOCET, S);
    Prelozit(S, p, "pocet");

    /*
    for (int i = 0; i < p; i++){
        printf("%s %s\n", S[i].cesky, S[i].anglicky);
    }
    */
}