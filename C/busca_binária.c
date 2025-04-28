#include <stdio.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* busca_binaria_arvore(No* raiz, int x) {
    if (raiz == NULL) {
        return NULL;
    }

    if (raiz->valor == x) {
        return raiz;
    } else if (x < raiz->valor) {
        return busca_binaria_arvore(raiz->esquerda, x);
    } else {
        return busca_binaria_arvore(raiz->direita, x);
    }
}