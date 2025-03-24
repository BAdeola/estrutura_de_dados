#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main(){
    lista lista1, lista2, lista3;
    init_lista(&lista1);
    init_lista(&lista2);

    lst_inserir_final(&lista1, 1);
    lst_inserir_final(&lista1, 3);
    lst_inserir_final(&lista1, 5);

    lst_inserir_final(&lista2, 2);
    lst_inserir_final(&lista2, 4);
    lst_inserir_final(&lista2, 6);

    printf("Lista 1: ");
    lst_imprimir(lista1);
    printf("\nLista 2: ");
    lst_imprimir(lista2);

    if (lst_concatenar(lista1, lista2, &lista3)) {
        printf("\nLista concatenada: ");
        lst_imprimir(lista3);
    } else {
        printf("\nErro: A lista concatenada ultrapassaria o limite de elementos.\n");
    }

    return 0;
}
