#ifndef _LISTA_H
#define _LISTA_H
#include <stdbool.h>

#define TAMANHO_LISTA 10

typedef int data;

typedef struct {
    data dados[TAMANHO_LISTA];
    int qt_elementos;
} lista;

///Se a lista está cheia
bool is_full(lista l);

void init_lista(lista * l);

///Determinar o número de nós de uma lista;
int tamanho_lista(lista l);

//Acessar o k-ésimo nó da lista;
bool acessar(lista l, int k, data* val);

//Alterar o valor do k-ésimo nó da lista
bool alterar(lista* l, int k, data val);

//Localizar um nó que contém um determinado valor
int localizar(lista l, data val);

//Inserir um novo nó na k-ésima posição da lista;
bool inserir(lista* l, int k, data val);

//Remover o k-ésimo nó da lista;
bool remover(lista* l, int k, data * val);

//Concatenar duas listas;
bool concat(lista l1, lista l2, lista* l3);

void lst_imprimir(lista l);

bool lst_ins_ordenado(lista * l, data val);

///5. Implemente uma função de protótipo bool lst_inserir_final(lista * l, lst_info x); que insere x no final da lista l e devolve verdadeiro para indicar o sucesso da operação, ou falso, para indicar a falha (lista cheia).
bool lst_inserir_final(lista * l, data val);
///6. Implemente uma função de protótipo bool lst_inserir_inicio(lista * l, lst_info x); que insere x no início da lista l e devolve verdadeiro para indicar o sucesso da operação, ou falso, para indicar a falha (lista cheia).
bool lst_inserir_inicio(lista * l, data val);
///7. Implemente uma função de protótipo bool lst_remover_final(lista * l, lst_info * x); que remove o valor do final da lista, guarda seu valor em x e devolve verdadeiro para indicar o sucesso da operação, ou falso, para indicar a falha (lista vazia).
bool lst_remover_final(lista * l, data val);
///8. Implemente uma função de protótipo bool lst_remover_inicio(lista * l, lst_info * x); que remove o valor do início da lista, guarda seu valor em x e devolve verdadeiro para indicar o sucesso da operação, ou falso, para indicar a falha (lista vazia).
bool lst_remover_inicio(lista * l, data val);



#endif // _LISTA_H
