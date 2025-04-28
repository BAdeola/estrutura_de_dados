#include "lista_enc.h"
#include <stdlib.h>
#include <stdio.h>

void lst_init(lista_encadeada* l) {
	l->comeco = NULL;
	l->qtd = 0;
}

bool acessar(lista_encadeada* l, int k, no_lista** ret) {
	if (k < 0 || k >= l->qtd) {
		return false;
	}

	*ret = l->comeco;

	for (int i = 0; i < k; i++) {
		*ret = (*ret)->prox;
	}

	return true;
}

bool inserir(lista_encadeada* l, int k, t_dado v) {

	/// Se esta fora da capacidade na lista, nao insere
	if (k < 0) {
		return false;
	}
	///Se tento inserir fora da quantidade de nós da lista, não insere
	if (k > l->qtd) {
		return false;
	}

	struct no* novo_no = NULL, ** acesso_no = NULL;

	//Acessa o numero
	acesso_no = &l->comeco;
	int i;
	for (i = 0; i < k - 1; i++) {
		acesso_no = &(*acesso_no)->prox;
	}

	if (k == 0){
		if (*acesso_no == NULL) {
			//Lista vazia
			*acesso_no = (struct no*)malloc(sizeof(struct no));
			(*acesso_no)->dado = v;
			(*acesso_no)->prox = NULL;
		} else {
			// Lista não vazia
			novo_no = (struct no*)malloc(sizeof(struct no));
			(novo_no)->prox = l->comeco;
			(novo_no)->dado = v;
			l->comeco = novo_no;
		}
	} else {
		novo_no = (struct no*)malloc(sizeof(struct no));
		(novo_no)->dado = v;
		if (*acesso_no == NULL) {
			(*acesso_no) = novo_no;
			(novo_no)->prox = NULL;
		} else {
			(novo_no)->prox = (*acesso_no)->prox;
			(*acesso_no)->prox = (novo_no);
		}
	}

	l->qtd++;


	return true;

}

bool remover(lista_encadeada* l, int k, t_dado *v) {
	if (k < 0 || k >= l->qtd || l->qtd == 0) {
		return false;
	}

	if (k == 0) {
		struct no* temp = l->comeco;
		*v = temp->dado;
		l->comeco = temp->prox;
		free(temp);
	} else {
		struct no* atual = l->comeco;
		int i;
		for (i = 0; i < k - 1; i++) {
			atual = atual->prox;
		}
		struct no* remover = atual->prox;
		*v = remover->dado;
		atual->prox = remover->prox;
		free(remover);
	}

	l->qtd--;
	return true;
}


void mostrar_lista(lista_encadeada l) {
	struct no* atual = l.comeco;
	while (atual) { //atual != NULL
		printf("[%d]", atual->dado);
		atual = atual->prox;
	}
	printf("\n==========================\n");

}
