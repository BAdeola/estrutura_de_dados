#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int conteudo;
    struct No *esquerda, *direita;
} No;

typedef struct Arvore {
    No *raiz;
    int qnt;
} Arvore;

void inserirEsquerda (No *no, int valor) {
    if (no->esquerda == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->conteudo = valor;
        novo->direita = NULL;
        novo->esquerda = NULL;
        no->esquerda = novo;
    } else {
        if (no->esquerda->conteudo > valor){
            inserirEsquerda(no->esquerda, valor);
        } else {
            inserirDireita(no->esquerda, valor);
        }
    } 
}

void inserirDireita (No *no, int valor) {
    if (no->direita == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->conteudo = valor;
        novo->direita = NULL;
        novo->esquerda = NULL;
        no->direita = novo;
    } else {
        if (no->direita->conteudo < valor) {
            inserirDireita(no->direita, valor);
        } else {
            inserirEsquerda(no->direita, valor);
        }
    }
}

void inserir(Arvore *arv, int valor){
    if (arv -> raiz == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->conteudo = valor;
        novo->direita = NULL;
        novo->esquerda = NULL;
        arv->raiz = novo;
    } else {
        if (valor < arv->raiz->conteudo) {
            inserirEsquerda(arv->raiz, valor);
        } else {
            inserirDireita(arv->raiz, valor);
        }
    }
}

void impressao(No *raiz){
    if (raiz != NULL) {
        printf("%d ", raiz->conteudo);
        impressao(raiz->esquerda);
        impressao(raiz->direita);
    }
}

int main(){
    


    return 0;
}
