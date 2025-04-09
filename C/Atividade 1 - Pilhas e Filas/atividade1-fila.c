#include <stdio.h>

typedef int t_dado;

#define MAX_TAM 10

typedef struct {
    t_dado itens[MAX_TAM];
    int inicio, fim;
} fila;

void inicializarFila (fila * f){
    f->inicio = f->fim = 0;
}

int filaCheia(fila * f){
    if (f->fim == MAX_TAM)
    {
        return 1;
    } else {
        return 0;
    }  
}

void enqueue(fila * f, t_dado valor){
    if (filaCheia(f) == 1)
    {
        printf("A fila está cheia.");
        return;
    } else{
        f->itens[f->fim] = valor;
        f->fim++;
    }
}

int filaVazia(fila * f){
    if (f->fim == 0)
    {
        return 1;
    } else {
        return 0;
    }
}

int dequeue(fila * f){
    if (filaVazia(f) == 1)
    {
        printf("Fila vazia, insira um número primeiro");
        return 1;
    } else {
        int valor = f->itens[f->fim-1];
        f->fim--;
        return valor;
    }
}

int front(fila * f) {
    if (filaVazia(f) == 1)
    {
        printf("Fila vazia, insira um número primeiro");
        return 1;
    } else {
        return f->itens[f->inicio];
    }
}

int rear(fila * f){
    if (filaVazia(f) == 1)
    {
        printf("Fila vazia, insira um número primeiro");
        return 1;
    } else {
        return f->itens[(f->fim-1)];
    }
}

void exibirFila(fila * f){
    if (filaVazia(f) == 1)
    {
        printf("Fila vazia, insira um valor primeiro");
        return;
    } else {
        int i;
        for (i = 0; i < f->fim; i++)
        {
            printf("[%d] ", f->itens[i]);
        }
        printf("\n");     
    }
}

int main(void){
    fila f;

    inicializarFila(&f);

    int i;
    for (i = 1; i <= 10; i++)
    {
        enqueue(&f, i);
    }

    exibirFila(&f);

    printf("%d\n", rear(&f));

    printf("%d\n", front(&f));

    for (i = 0; i < 5; i++)
    {
        printf("%d\n", dequeue(&f));
    }

    exibirFila(&f);

    return 0;
}