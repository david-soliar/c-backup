#include <stdio.h>

int main()
{
    /* prevedeme 120 stupnu fahrenheita*/
    float fahrenheit = 120.0;
    float celsius = 0;

    /* spocteme (C) podle vzorce */
    celsius = (5 * (fahrenheit - 32)) / 9;

    /* vypiseme vysledek */
    printf("Teplota je %f (C)",celsius);

    return 0;
}
