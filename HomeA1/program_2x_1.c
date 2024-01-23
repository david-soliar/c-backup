#include <stdio.h>

int main()
{
    /* prevedeme 120 stupnu fahrenheita*/
    float usd = 15;
    float czk = 0;

    /* spocteme (C) podle vzorce */
    czk = usd*22.9;

    /* vypiseme vysledek */
    printf("%f(USD) je %f(czk)", usd, czk);

    return 0;
}
