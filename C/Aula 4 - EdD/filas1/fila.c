#include <stdio.h>
#include "fila.h"

///Inicializa a fila
void queue_init(fila * f){
    f->qtd = f->inicio = f->fim = 0;
}

///Verifica se a fila ta vazia
bool queue_empty(fila f){
    return f.qtd == 0;
}

///Verifica se a fila ta cheia
bool queue_full(fila f){
    return f.qtd == TAM_MAX;
}

///Coloca um valor novo na fila
bool enqueue(fila * f, t_dado v){
    if(queue_full(*f)){
        return false;
    }


    f->itens[f->fim] = v;
    f->fim = (f->fim + 1)%TAM_MAX;
    f->qtd++;

    return true;
}


///Remove um valor da fila
bool dequeue(fila * f, t_dado * v){
    if(queue_empty(*f)){
        return false;
    }


    *v = f->itens[f->inicio];
    f->inicio = (f->inicio + 1)%TAM_MAX;
    f->qtd--;

    return true;
}

///Mostra a fila na tela
void print_queue(fila f){
    int i, j;
    for(i = 0, j = f.inicio; i < f.qtd; i++){
        printf("[%d]", f.itens[j]);
        j = (j + 1)%TAM_MAX;
    }
    printf("\n");
}

bool dequeue_and_test(fila * f, queue_info * x){
    if(queue_empty(*f)){
        return false;
    }

    *x = f->itens[f->inicio];
    f->inicio = (f->inicio + 1)%TAM_MAX;
    f->qtd--;

    return true;
}

bool deque_push_front (fila * f, t_dado v) {
    if(queue_full(*f)){
        return false;
    }

    if (queue_empty(*f)) {
        f->inicio = f->fim = 0;
    } else {
        f->inicio = (f->inicio - 1 + TAM_MAX) % TAM_MAX;
    }

    f->itens[f->inicio] = v;
    f->qtd++;

    return true;
}

bool deque_push_back(fila * f, t_dado v){
    if(queue_full(*f)){
        return false;
    }

    if (queue_empty(*f)) {
        f->inicio = f->fim = 0;
    } else {
        f->fim = (f->fim + 1) % TAM_MAX;
    }

    f->itens[f->fim] = v;
    f->qtd++;

    return true;
}

bool deque_pop_front(fila * f, t_dado * v){
    if(queue_empty(*f)){
        return false;
    }


    *v = f->itens[f->inicio];
    f->inicio = (f->inicio + 1)%TAM_MAX;
    f->qtd--;

    return true;
}

bool deque_pop_back(fila * f, t_dado * v){
    if(queue_empty(*f)){
        return false;
    }

    *v = f->itens[f->fim];

    if (f->fim == 0) {
        f->fim = TAM_MAX - 1;
    } else {
        f->fim--;
    }

    f->qtd--;

    return true;
}

void deque_print(fila f){
    int i, j;
    for(i = 0, j = f.inicio; i < f.qtd; i++){
        printf("[%d]", f.itens[j]);
        j = (j + 1)%TAM_MAX;
    }
    printf("\n");
}

///fila de prioridade
void fp_init(fila * f){
    f->qtd = f->inicio = f->fim = 0;
}

bool fp_isfull (fila f) {
    return f.qtd == TAM_MAX;
}

bool fp_isempty(fila f) {
    return f.qtd == 0;
}

int busca_binaria(fila * f, t_dado v) {
    int esq = 0, dir = f->qtd - 1;
    int meio, posicao = f->qtd;

    while (esq <= dir) {
        meio = (esq + dir) / 2;
        int idx = (f->inicio + meio) % TAM_MAX;

        if (f->itens[idx] == v) {
            posicao = meio;
            break;
        } else if (f->itens[idx] > v) {
            posicao = meio;
            dir = meio - 1;
        } else {
            esq = meio + 1;
        }
    }
    return posicao;
}

bool fp_enqueue(fila * f, int v) {
    if (fp_isfull(*f)) {
        return false;
    }

    int posicao = busca_binaria(f, v);
    int i;

    for (i = f->qtd; i > posicao; i--) {
        int de = (f->inicio + i - 1) % TAM_MAX;
        int para = (f->inicio + i) % TAM_MAX;
        f->itens[para] = f->itens[de];
    }

    int insert_idx = (f->inicio + posicao) % TAM_MAX;
    f->itens[insert_idx] = v;

    f->fim = (f->fim + 1) % TAM_MAX;
    f->qtd++;

    return true;
}

bool fp_dequeue(fila * f, int * v) {
    if (fp_isempty(*f)) {
        return false;
    }

    *v = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAM_MAX;
    f->qtd--;

    return true;
}
