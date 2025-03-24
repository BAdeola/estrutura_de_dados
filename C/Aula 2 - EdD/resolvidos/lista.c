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
    if (k < 0 || k > l->qt_elementos)
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
    if (k < 0 || k > l.qt_elementos)
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

bool remover(lista* l, int k, data * val) {
    if (k < 0 || k > l->qt_elementos)
        return false;

    if (l->qt_elementos == 0)
        return false;

    (*val) = l->dados[k];

    int i;
    for (i = k; i < l->qt_elementos; i++) {
        l->dados[i] = l->dados[i + 1];
    }

    l->qt_elementos--;

    return true;
}

//Concatenar duas listas;
bool concat(lista l1, lista l2, lista* l3){

    if(l1.qt_elementos + l2.qt_elementos > TAMANHO_LISTA)
        return false;

    init_lista(l3);

    int i;
    for(i = 0; i < l1.qt_elementos; i++){
        lst_ins_ordenado(l3, l1.dados[i]);
    }

    for(i = 0; i < l2.qt_elementos; i++){
        lst_ins_ordenado(l3, l2.dados[i]);
    }

    return true;

}

void lst_imprimir(lista l){
    int i;
    for(i = 0; i < l.qt_elementos; i++){
        printf("[%d]", l.dados[i]);
    }
    printf("\n");
}


bool lst_ins_ordenado(lista * l, data val){
    ///Buscar onde inserir
    int k;
    for(k = 0; k < l->qt_elementos; k++){
        if(l->dados[k] >= val){
            break;
        }
    }

    ///Inserir no local encontrado
    return inserir(l, k, val);
}

///5. Implemente uma função de protótipo bool lst_inserir_final(lista * l, lst_info x); que insere x no final da lista l e devolve verdadeiro para indicar o sucesso da operação, ou falso, para indicar a falha (lista cheia).
bool lst_inserir_final(lista * l, data val){
    return inserir(l, l->qt_elementos, val);
}
///6. Implemente uma função de protótipo bool lst_inserir_inicio(lista * l, lst_info x); que insere x no início da lista l e devolve verdadeiro para indicar o sucesso da operação, ou falso, para indicar a falha (lista cheia).
bool lst_inserir_inicio(lista * l, data val){
    return inserir(l, 0, val);
}
///7. Implemente uma função de protótipo bool lst_remover_final(lista * l, lst_info * x); que remove o valor do final da lista, guarda seu valor em x e devolve verdadeiro para indicar o sucesso da operação, ou falso, para indicar a falha (lista vazia).
bool lst_remover_final(lista * l, data val){
    return remover(l, l->qt_elementos - 1, val);
}
///8. Implemente uma função de protótipo bool lst_remover_inicio(lista * l, lst_info * x); que remove o valor do início da lista, guarda seu valor em x e devolve verdadeiro para indicar o sucesso da operação, ou falso, para indicar a falha (lista vazia).
bool lst_remover_inicio(lista * l, data val){
    return remover(l, 0, val);
}
