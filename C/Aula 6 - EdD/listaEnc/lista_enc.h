#ifndef LISTA_ENC_H_
#define LISTA_ENC_H_

#include <stdbool.h>
#include <stdlib.h>

typedef int t_dado;

typedef struct no {
	t_dado dado;
	struct no* prox;
} no_lista;

typedef struct {
	struct no* comeco;
	int qtd;
} lista_encadeada;


void lst_init(lista_encadeada* l);

///Acessar o k-ésimo nó da lista;
bool acessar(lista_encadeada* l, int k, no_lista** ret);

///Inserir um novo nó na k-ésima posição da lista;
bool inserir(lista_encadeada* l, int k, t_dado v);

///Remover o k-ésimo nó da lista;
bool remover(lista_encadeada* l, int k, t_dado *v);

//Mostra lista
void mostrar_lista(lista_encadeada l);
#endif
