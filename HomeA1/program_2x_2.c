#include <stdio.h>

int main()
{
    /* prevedeme 120 stupnu fahrenheita*/
    float degrees = 45;
    float radians = 0;
    float pi = 3.141592;

    /* spocteme (C) podle vzorce */
    radians = (degrees*pi)/180;

    /* vypiseme vysledek */
    printf("Uhol %f(stupnov) je %f(rad)", degrees, radians);

    return 0;
}
