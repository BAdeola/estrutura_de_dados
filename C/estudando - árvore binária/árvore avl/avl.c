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

No * rotacaoEsquerda(No * r){
    No *y, *f;

    y = r->direita;
    f = y->esquerda;

    y->esquerda = r;
    r->direita = f;

    r->altura = maior(alturaDoNo(r->esquerda), alturaDoNo(r->direita)) + 1;
    y->altura = maior(alturaDoNo(y->esquerda), alturaDoNo(y->direita)) + 1;

    return y;
}

No * rotacaoDireita(No * r){
    No *y, *f;

    y = r->esquerda;
    f = y->direita;

    y->direita = r;
    r->esquerda = f;

    r->altura = maior(alturaDoNo(r->esquerda), alturaDoNo(r->direita)) + 1;
    y->altura = maior(alturaDoNo(y->esquerda), alturaDoNo(y->direita)) + 1;

    return y;
}

No* rotacaoDireitaEsquerda(No* r){
    r->direita = rotacaoDireita(r->direita);
    return rotacaoEsquerda(r);
}

No* rotacaoEsquerdaDireita(No* r){
    r->esquerda = rotacaoEsquerda(r->esquerda);
    return rotacaoDireita(r);
}

No* balancear(No* raiz){
    short fb = fatorDeBalancemaneto(raiz);

    //Rotação para esquerda
    if (fb < -1 && fatorDeBalancemaneto(raiz->direita) <= 0)
        raiz = rotacaoEsquerda(raiz);
    
    //Rotação direita
    else if (fb > 1 && fatorDeBalancemaneto(raiz->esquerda) >= 0)
        raiz = rotacaoDireita(raiz);

    //Rotação dupla esquerda
    else if (fb > 1 && fatorDeBalancemaneto(raiz->esquerda) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);
    //Rotação dupla direita
    else if (fb < -1 && fatorDeBalancemaneto(raiz->esquerda) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);
    
    return raiz;
}

No* inserir(No* raiz, int x){
    if(raiz == NULL)
        return novoNo(x);
    else {
        if(x < raiz->conteudo)
            raiz->esquerda = inserir(raiz->esquerda, x);
        else if(x > raiz->conteudo)
            raiz->direita = inserir(raiz->esquerda, x);
        else
            printf("\nInserção não realizada!\nO elemento %d já existe.\n", x);
    }

    raiz->altura = maior(alturaDoNo(raiz->direita), alturaDoNo(raiz->esquerda)) + 1;

    raiz = balancear(raiz);

    return raiz;
}

