#ifndef _FILA_H_
#define _FILA_H_
#include <stdbool.h>

#define TAM_MAX 10

typedef int queue_info;
typedef int t_dado;

typedef struct {
    t_dado itens[TAM_MAX];
    int inicio, fim, qtd;
} fila;

///Inicializa a fila
void queue_init(fila * f);
///Verifica se a fila ta vazia
bool queue_empty(fila f);
///Verifica se a fila ta cheia
bool queue_full(fila f);
///Coloca um valor novo na fila
bool enqueue(fila * f, t_dado v);
///Remove um valor da fila
bool dequeue(fila * f, t_dado * v);
///Mostra a fila na tela
void print_queue(fila f);
///Mostra qual foi a �ltima vari�vel retirada da fila
bool dequeue_and_test(fila * f, queue_info * x);
///deque:
bool deque_push_front (fila * f, t_dado v);
bool deque_push_back(fila * f, t_dado v);
bool deque_pop_front(fila * f, t_dado * v);
bool deque_pop_back(fila * f, t_dado * v);
void deque_print(fila f);

///fila prioritaria:
void fp_init(fila * f);
bool fp_isfull (fila f);
bool fp_isempty(fila f);
int busca_binaria(fila * f, t_dado v);
bool fp_enqueue(fila * f, int v);
bool fp_dequeue(fila * f, int * v);

#endif // _FILA_H_
