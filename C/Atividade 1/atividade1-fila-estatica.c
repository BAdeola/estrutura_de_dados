#include <stdio.h>

typedef int t_dado;

#define MAX_TAM 10

typedef struct {
    t_dado itens[MAX_TAM];
    int qtd;
} fila;

void inicializarLista(fila * f){
    f->qtd = 0;
}

void inserirElemento(fila * f, t_dado valor){
    if (f->qtd == MAX_TAM)
    {
        printf("Fila cheia, nao foi possivel inserir o valor.");
        return;
    } else {
        f->itens[f->qtd] = valor;
        f->qtd++;
    }
}

int removerElemento(fila * f){
    if (f->qtd == 0)
    {
        printf("A fila esta vazia, adicione um valor primeiro.");
        return;
    } else {
        int valor = f->itens[f->qtd-1];
        return valor;
    }
}

int acessarElementos(fila * f, t_dado indice){
    if (indice>f->qtd)
    {
        printf("Indice maior que a quatidade de itens na fila, retorne um valor de 0 a %d", f->qtd);
        return;
    } else {
        return f->itens[indice];
    }
}

void exibirFila(fila * f){
    if (f->qtd == 0)
    {
        printf("Fila vazia, insira um valor primeiro");
        return;
    } else {
        int i;
        for (i = 0; i < f->qtd; i++)
        {
            printf("[%d] ", f->itens[i]);
        }      
    }
}

int main(void){
    return 0;
}