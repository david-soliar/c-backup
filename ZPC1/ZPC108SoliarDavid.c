#include <stdio.h>
#include <string.h>

#define RADKY 30
#define SLOUPCE 60

typedef struct { char kod; union { short x,y,delka; char znak,smer; } u; } Instr;

#include "u08.inc"

void main(){
    char K[RADKY][SLOUPCE];
    memset(K,' ',sizeof K);
    int x, y, delka;
    char znak, smer;
    for (int i = 0; i < KRESBA; i++){
        switch (kresba[i].kod){
            case 1:
                x = kresba[i].u.x;
                break;
            
            case 2:
                y = kresba[i].u.y;
                break;

            case 3:
                znak = kresba[i].u.znak;
                break;

            case 4:
                delka = kresba[i].u.delka;
                break;
            
            case 5:
                switch (kresba[i].u.smer){
                    case 2:
                        for (int i = 0; i < delka; i++){
                            K[y][x] = znak;
                            y++;
                        }
                        break;

                    case 1:
                        for (int i = 0; i < delka; i++){
                            K[y][x] = znak;
                            x++;
                        }
                        break;

                    case -1:
                        for (int i = 0; i < delka; i++){
                            K[y][x] = znak;
                            x--;
                        }
                        break;

                    case -2:
                        for (int i = 0; i < delka; i++){
                            K[y][x] = znak;
                            y--;
                        }
                        break;
                }
                break;
        }
    }
    for (int y_K = 0; y_K < RADKY; y_K++){
        for (int x_K = 0; x_K < SLOUPCE; x_K++){
            printf("%c", K[y_K][x_K]);
        }
        printf("\n");
    }
    
}