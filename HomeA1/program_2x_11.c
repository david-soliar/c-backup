#include <stdio.h>

void main() {
    int numbers[5] = {5, 9, 7, 1, 6};
    int i;
    char slovo[] = "bruh2";
    for (i = 0; i < 5; i++) {
        printf("%i%c\n", numbers[i], slovo[i]);
    }
    printf("%s", slovo);
}