#ifndef _LISTA_H
#define _LISTA_H
#include <stdbool.h>

#define TAMANHO_LISTA 10

typedef int data;

typedef struct {
    data dados[TAMANHO_LISTA];
    int qt_elementos;
} lista;

///Se a lista est� cheia
bool is_full(lista l);

void init_lista(lista * l);

///Determinar o n�mero de n�s de uma lista;
int tamanho_lista(lista l);

//Acessar o k-�simo n� da lista;
bool acessar(lista l, int k, data* val);

//Alterar o valor do k-�simo n� da lista
bool alterar(lista* l, int k, data val);

//Localizar um n� que cont�m um determinado valor
int localizar(lista l, data val);

//Inserir um novo n� na k-�sima posi��o da lista;
bool inserir(lista* l, int k, data val);

//Remover o k-�simo n� da lista;
bool remover(lista* l, int k, data * val);

//Concatenar duas listas;
bool concat(lista l1, lista l2, lista* l3);

void lst_imprimir (lista 1);

bool lst_ins_ordenado(lista * 1, data val);

bool lst_concatenar(lista lst1, lista lst2, lista * lst3);

bool lst_inserir_final(lista * l, data x);

bool lst_inserir_inicio(lista * l, data x);

bool lst_remover_final(lista * l, data * x);

bool lst_remover_inicio(lista * l, data * x);

#endif // _LISTA_H
