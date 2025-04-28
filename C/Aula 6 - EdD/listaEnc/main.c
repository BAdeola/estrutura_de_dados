#include <stdio.h>
#include "lista_enc.h"

int main() {

	lista_encadeada l1;

	lst_init(&l1);
	for (int i = 0; i < 10; i++) {
		inserir(&l1, i, i);
	}
	mostrar_lista(l1);
	t_dado v;
	for (int i = 0; i < 10; i++) {
		remover(&l1, 1, &v);
	}
	mostrar_lista(l1);
	for (int i = 0; i < 12; i++) {
		inserir(&l1, i, i);
	}
	mostrar_lista(l1);

	return 0;
}
