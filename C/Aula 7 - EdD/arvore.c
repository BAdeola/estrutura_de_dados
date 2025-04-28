#include "arvore.h"
#include <stdio.h>
#include <stdbool.h>

void insere_ordenado( no arvore[], int posicao_vetor, int valor,  no * pai){

    if(posicao_vetor == 0){
        pai->dado = valor;
        pai->dir = pai->esq = 0;
    } else {
        if(valor < pai->dado){
            if(!pai->esq){
                pai->esq = &arvore[posicao_vetor];
                arvore[posicao_vetor].dado = valor;
                arvore[posicao_vetor].esq = arvore[posicao_vetor].dir = 0;
            } else {
                insere_ordenado(arvore, posicao_vetor, valor, pai->esq);
            }
        }else {
            if(!pai->dir){
                pai->dir = &arvore[posicao_vetor];
                arvore[posicao_vetor].dado = valor;
                arvore[posicao_vetor].esq = arvore[posicao_vetor].dir = 0;
            } else {
                insere_ordenado(arvore, posicao_vetor, valor, pai->dir);
            }
        }
    }
}

void print_pre(no *no){
    if(no == 0)
        return;
    ///Mostro
    printf(" %d", no->dado);
    ///Esquerda
    print_pre(no->esq);
    ///Direita
    print_pre(no->dir);
}

void print_in(no* no) {
    if (no == 0)
        return;
    ///Esquerda
    print_in(no->esq);
    ///Mostro
    printf(" %d", no->dado);
    ///Direita
    print_in(no->dir);
}

void print_post(no* no) {
    if (no == 0)
        return;
    ///Esquerda
    print_post(no->esq);
    ///Direita
    print_post(no->dir);
    ///Mostro
    printf(" %d", no->dado);
}
