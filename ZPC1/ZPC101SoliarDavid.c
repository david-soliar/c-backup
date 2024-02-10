#include <stdio.h>

void main() {
    int u, v, r;
    printf("zadaj dve prirodzene cisla: ");
    scanf("%i %i", &u, &v);
    while (v>0){
        r = u%v;
        u = v;
        v = r;
    }
    printf("najvacsi spolocny delitel: %i", u);
    
}