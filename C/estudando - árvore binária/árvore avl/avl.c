#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int conteudo;
    struct No *esquerda, *direita;
    short altura;
} No;

No * novoNo(int x){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->conteudo = x;
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->altura = 0;
    }
    else
        printf("\nERRO ao alocar o novo nó.\n");
    return novo;
}

short maior(short a, short b){
    return (a > b)? a:b;
}

short alturaDoNo(No * no){
    if (no == NULL)
        return -1;
    else
        return no->altura;   
}

short fatorDeBalancemaneto(No * no){
    if (no)
        return (alturaDoNo(no->esquerda) - alturaDoNo(no->direita));
    else
        return 0;
}

