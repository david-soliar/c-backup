#include <stdio.h>

void prvy_riadok(int x){
    for (int i = 0; i <= x; i++){
        if (i==0){
            printf("%*X ",5, i);
            continue;
        }
        if (i==16){
            printf("%-*X", 3, i);
            continue;
        }
        printf("%-2X", i);
    }
    printf("\n");
}

void druhy_riadok(int x){
    for (int i = 0; i <= x; i++){
        if (i==0){
            printf("%*s", 3, "-");
            continue;
        }
        printf("%s", "-");
    }
    printf("\n");
}

void hex_tab(){
    for (int y = 0; y <= 8; y++){
        if (y==0){
            prvy_riadok(15);
            continue;
        }
        if ((y==1) || (y==8)){
            druhy_riadok(15*2+4);
            continue;
        }
        
        for (int x = -1; x <= 16; x++){
            if (x==-1){
                printf("%i|", y*10);
                continue;
            }

            if (x==16){
                printf(" |\n");
                continue;
            }
            
            switch (y*16+x){
                case 32:
                case 127:
                    printf("  ");
                    break;
                default:
                    printf("%*c", 2, y*16+x);
                    break;
            }
            
        }
        
    }
}

void dec_tab(){
    for (int y = 1; y <= 13; y++){
        if (y==1){
            printf(" ");
            prvy_riadok(9);
            continue;
        }
        if ((y==2) || (y==13)){
            printf(" ");
            druhy_riadok(9*2+4);
            continue;
        }

        for (int x = -1; x <= 10; x++){
            if (x==-1){
                printf("%*i|", 3, y*10);
                continue;
            }

            if (x==10){
                printf(" |\n");
                continue;
            }
            
            switch (y*10+x){
                case 30:
                case 31:
                case 127:
                case 128:
                case 129:
                    printf("  ");
                    break;
                default:
                    printf("%*c", 2, y*10+x);
                    break;
            }
            
        }
    }
}

void main(){
    printf("\n HEX TAB\n");
    hex_tab();

    printf("\n\n DEC TAB\n");
    dec_tab();
}