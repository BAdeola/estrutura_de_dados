#include "lista.h"

bool is_full(lista l){
    return (l.qt_elementos == TAMANHO_LISTA);
}

void init_lista(lista * l){
    l->qt_elementos = 0;
    int i;
    for (i = 0; i < TAMANHO_LISTA; i++){
        l->dados[i] = 0;
    }
}

//Alterar o valor do k-ésimo nó da lista;
bool alterar(lista* l, int k, data val) {
    if (k < 0 || k >= l->qt_elementos)
        return false;

    l->dados[k] = val;
    return true;
}


///Determinar o número de nós de uma lista;
int tamanho_lista(lista l){
    return l.qt_elementos;
}

//Acessar o k-ésimo nó da lista;
bool acessar(lista l, int k, data* val) {
    if (k < 0 || k >= l.qt_elementos)
        return false;

    (*val) = l.dados[k];
    return true;
}

//Localizar um nó que contém um determinado valor
int localizar(lista l, data val) {
    int i;
    for (i = 0; i < l.qt_elementos; i++) {
        if (val == l.dados[i]) {
            return i;
        }
    }
    return -1;
}

//inserir no local indicado
bool inserir(lista * l, int k, data val) {
    if (k < 0 || k > l->qt_elementos)
        return false;

    if (l->qt_elementos == TAMANHO_LISTA)
        return false;

    int i;
    for (i = l->qt_elementos; i >= k; i--) {
        l->dados[i] = l->dados[i-1];
    }

    l->dados[k] = val;
    l->qt_elementos++;

    return true;
}

//Remover valor determinado pelo usuário
bool remover(lista* l, int k, data * val) {
    if (k < 0 || k >= l->qt_elementos)
        return false;

    if (l->qt_elementos == 0)
        return false;

    *val = l->dados[k];

    int i;
    for (i = k; i < l->qt_elementos - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }

    l->qt_elementos--;

    return true;
}


//Imprimir lista
void lst_imprimir(lista l) {
    int i;
    for (i = 0; i < l.qt_elementos; i++) {
        printf("%d", l.dados[i]);
        if (i < l.qt_elementos - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

//Concatenar duas listas;
bool lst_concatenar(lista lst1, lista lst2, lista *lst3) {
    if (lst1.qt_elementos + lst2.qt_elementos > TAMANHO_LISTA) {
        return false;
    }

     init_lista(l3);

    int i;

    for (i = 0; i < lst1.qt_elementos; i++) {
        lst_ins_ordenado(l3, l1.dados[i]);
    }

    for (i = 0; i < lst2.qt_elementos; i++) {
        lst_ins_ordenado(l3, l2.dados[i]);
    }

    return true;
}

bool lst_inserir_final(lista* l, data x) {
    return inserir(l, l->qt_elementos, x);
}

bool lst_inserir_comeco(lista* l, data x) {
    return inserir(l, 0, x);
}

bool lst_inserir_ordenado(lista* l, data val) {
    int i;
    for (i = 0; i < l->qt_elementos; i++) {
        if (l->dados[i] > val) {
            return inserir(l, i, val);
        }
    }
    return inserir(l, l->qt_elementos, val);
}
