#include <stdio.h>
#include <assert.h>

void main(){
    char img[30][80];
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 80; j++){
            img[i][j] = ' ';
        }
    }
    
    short x=0, y=0, dx, dy, c;
    char znak, op;
    char word[10];
    FILE *F=fopen("Kresba","rb");
    
    while (fread(&op,sizeof(char),1,F)){
        switch (op){
            case 1:
                fread(&x,sizeof(short),1,F);
                fread(&y,sizeof(short),1,F);
                break;
            case 2:
                fread(&dx,sizeof(short),1,F);
                x+=dx;
                fread(&dy,sizeof(short),1,F);
                y+=dy;
                break;
            case 3:
                fread(&znak,sizeof(char),1,F);
                fread(&dx,sizeof(short),1,F);
                fread(&dy,sizeof(short),1,F);
                fread(&c,sizeof(short),1,F);
                for (short i = 0; i < c; i++){
                    img[y][x] = znak;
                    x += dx;
                    y += dy;
                }
                break;
            case 4:
                fread(&dx,sizeof(short),1,F);
                fread(&dy,sizeof(short),1,F);
                fread(&c,sizeof(short),1,F);
                fread(word,sizeof(char),c,F);
                for (short i = 0; i < c; i++){
                    img[y][x] = word[i];
                    x += dx;
                    y += dy;
                }
                break;
            default:
                break;
        }
    }

    printf("\n");
    fclose(F);
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 80; j++){
            printf("%c", img[i][j]);
        }
        printf("\n");
    }
}
