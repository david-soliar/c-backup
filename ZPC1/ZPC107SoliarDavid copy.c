#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef enum { kus=1,kg } Jednotka;
typedef union { int kus; float kg; } Mnozstvi;
typedef struct { const char *potravina; Jednotka jednotka; Mnozstvi mnozstvi; } Pohyb;
#include "U07.inc"

void kus_pocet(int pocet, int i, char *vstup){
    if (i == POHYB){
        printf("%s %i kusov", vstup, pocet);
        return;
    }
    
    if ((pohyb[i].jednotka==1) && (strcmp(pohyb[i].potravina, vstup)==0)){
        pocet += pohyb[i].mnozstvi.kus;
    }

    kus_pocet(pocet, i+1, vstup);
}

float kg_pocet(float pocet, int i, char *vstup){
    if (i == POHYB){
        return (float)pocet;
    }
    if ((pohyb[i].jednotka==2) && (strcmp(pohyb[i].potravina, vstup)==0)){
        pocet += pohyb[i].mnozstvi.kg;
    }

    return kg_pocet(pocet, i+1, vstup);
}

void main(){
    while (1){
        char vstup[10];
        printf("\n\nzadaj potravinu ");
        scanf("%s", &vstup);
        if (!(isalpha(vstup[0]))){
            return;
        }
        
        int s = 0;

        int pocet_i = 0;
        float pocet_f = 0.0;
        for (int i = 0; i < POHYB; i++){
            if (strcmp(pohyb[i].potravina, vstup)==0){
                s = pohyb[i].jednotka;
                break;
            }
        }
        
        switch (s){
        case 1:
            kus_pocet(pocet_i, 0, vstup);
            break;

        case 2:
            printf("%g", kg_pocet(pocet_f, 0, vstup));
            break;

        default:
            printf("potravina nebola najdena");
            break;
        }
    }
}
