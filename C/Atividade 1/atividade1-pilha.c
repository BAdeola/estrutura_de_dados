#include <stdio.h>

typedef int t_dado;

#define MAX_TAM 10

typedef struct {
    t_dado itens[MAX_TAM];
    int topo;
} pilha;

void inicializarPilha (pilha * p) {
    p->topo=0;
}

int pilhaCheia (pilha * p){
    if (p->topo == MAX_TAM)
    {
        return 1;
    } else {
        return 0;
    }
}

void push(pilha * p, t_dado valor){
    if (pilhaCheia(p) == 1)
    {
        printf("Pilha cheia, nao foi possivel inserir o valor");
        return;
    } else {
        p->itens[p->topo] = valor;
        p->topo++;
    }
}

int pilhaVazia(pilha * p){
    if (p->topo == 0)
    {
        return 1;
    } else {
        return 0;
    }
}

int pop(pilha * p){
    if (pilhaVazia(p) == 1)
    {
        printf("Pilha vazia, insira um valor primeiro");
        return 1;
    } else {
        int valor = p->itens[--p->topo];
        return valor;
    }
}

int peek (pilha * p){
    if (pilhaVazia(p) == 1)
    {
        printf("Pilha vazia, insira um valor primeiro");
        return 1;
    } else {
        int valor = p->itens[p->topo - 1];
        return valor;
    }
}

void exibirPilha(pilha * p){
    if (pilhaVazia(p) == 1)
    {
        printf("Pilha vazia, insira um valor primeiro");
        return;
    } else {
        int i;
        for (i = 0; i < p->topo; i++)
        {
            printf("[%d] ", p->itens[i]);
        }
        printf("\n");     
    }
}


int main (void){
    pilha p;

    inicializarPilha(&p);
    push(&p, 16);
    push(&p, 20);
    push(&p, 30);
    push(&p, 80);

    exibirPilha(&p);

    printf("%d\n", pop(&p));
    printf("%d\n", pop(&p));

    exibirPilha(&p);

    printf("%d\n", pop(&p));

    exibirPilha(&p);

    return 0;
}
