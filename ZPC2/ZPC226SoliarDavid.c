#include <stdio.h>
#include <assert.h>

void main(){
    FILE *F=fopen("zpc2.txt","w");
    fputs("_________________________________________________________________________________________\n",F);
    
    int i = 32;
    while (i<127){
        fprintf(F, "|");
        
        fprintf(F, "%4i",i);
        fprintf(F, "%3X",i);
        fprintf(F, "%2c ",i);

        if ((i+1)%8==0){
            fprintf(F, "|\n");
        }
        i++;
    }
    fprintf(F, "|%4d%3X   |\n", 127, 127);
    fputs("_________________________________________________________________________________________\n",F);
    fclose(F);
    
    F=fopen("zpc2.txt","r");
    assert(F!=NULL);
    while (1) {
        int c;
        if (fscanf(F,"%c",&c)==EOF) {
            break;
        }
        printf("%c",c);
    }
    fclose(F);
}
