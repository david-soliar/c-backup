#include <stdio.h>

unsigned int delka(char str[]){
   unsigned int index = 0;
   while (str[index] != '\0') index++;
   return index;
}

void main(){
    int d = delka("Ahoj!"); /*-->5*/
    printf("%i\n", delka("tato veta ma 22 znakov"));
}