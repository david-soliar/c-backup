#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "Jmena2"

void main(){
    char mat [127][12];
    int akt_meno = 0;
    int last_i = 0;
    int dlzka;
    for (int i = 1; i < POCET+1; i++){
        if (isupper(Jmena[i]) || Jmena[i]=='\0'){
            dlzka = i-last_i;
            mat[akt_meno][0] = dlzka;

            for (int j = last_i; j < i; j++){
                mat[akt_meno][j-last_i+1] = Jmena[j];
            }

            mat[akt_meno][dlzka+1] = '\0';
            last_i = i;
            akt_meno++;
        }
    }
    int n;
    scanf("%i", &n);
    int x = 0;
    int d;
    for (int i = 0; i < 127; i++){
        d = mat[i][0];

        if (x+d>=n){
            x = 0;
        }
        if (x==0){
            printf("\n");
        }
        else {if (x+d<=n){
            printf(" ");
            x++;
        }}
        
        for (int j = 1; j < 12; j++){
            if (mat[i][j]=='\0'){
                break;
            }
            printf("%c", mat[i][j]);
        }
        x+=d;
    }
}