#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{

    fila f;
    t_dado retorno;
    srand(408);

    fp_init(&f);
    t_dado valor;

    printf("==== Teste de Enqueue ====\n");
    t_dado valores[] = {20, 5, 15, 10, 25, 30}; // 30 não será inserido (fila cheia)
    for (int i = 0; i < 6; i++) {
        printf("Enfileirando %d: ", valores[i]);
        if (fp_enqueue(&f, valores[i])) {
            printf("Sucesso!\n");
            print_queue(f);
        } else {
            printf("Fila cheia!\n");
        }
    }

    printf("\n==== Teste de Dequeue ====\n");
    while (fp_dequeue(&f, &valor)) {
        printf("Desenfileirou: %d\n", valor);
        print_queue(f);
    }

    printf("\n==== Teste de Fila Vazia ====\n");
    if (!fp_dequeue(&f, &valor)) {
        printf("Fila vazia!\n");
    }


    return 0;
}
