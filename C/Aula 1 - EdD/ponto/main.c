#include <stdio.h>
#include "ponto.h"

int main(){
    ponto p1, p2;
    int x, y, x1, y1;
    double valor;

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &x1);
    scanf("%d", &y1);
    pto_init(&p1, x, y);
    pto_init(&p2, x1, y1);

    valor = pto_distancia(p1, p2);

    printf("%lf", valor);

    return 0;
}
