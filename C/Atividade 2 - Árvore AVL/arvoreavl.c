#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHAVE 100

typedef struct {
    char chave[MAX_CHAVE];
    int cont;
} tipo_dado;

typedef struct avl_no {
    tipo_dado dado;
    int bal;
    struct avl_no* esq;
    struct avl_no* dir;
} *avl_tree;


void rotacao_esq(avl_tree* t) {
    avl_tree p = (*t)->dir;
    (*t)->dir = p->esq;
    p->esq = *t;
    *t = p;
}

void rotacao_dir(avl_tree* t) {
    avl_tree p = (*t)->esq;
    (*t)->esq = p->dir;
    p->dir = *t;
    *t = p;
}


void balance_esq(avl_tree* t) {
    avl_tree p = (*t)->esq;
    if (p->bal == -1) {
        (*t)->bal = 0;
        p->bal = 0;
        rotacao_dir(t);
    } else {
        avl_tree q = p->dir;
        switch (q->bal) {
            case -1: (*t)->bal = 1; p->bal = 0; break;
            case  0: (*t)->bal = 0; p->bal = 0; break;
            case  1: (*t)->bal = 0; p->bal = -1; break;
        }
        q->bal = 0;
        rotacao_esq(&(*t)->esq);
        rotacao_dir(t);
    }
}


void balance_dir(avl_tree* t) {
    avl_tree p = (*t)->dir;
    if (p->bal == 1) {
        (*t)->bal = 0;
        p->bal = 0;
        rotacao_esq(t);
    } else {
        avl_tree q = p->esq;
        switch (q->bal) {
            case  1: (*t)->bal = -1; p->bal = 0; break;
            case  0: (*t)->bal = 0; p->bal = 0; break;
            case -1: (*t)->bal = 0; p->bal = 1; break;
        }
        q->bal = 0;
        rotacao_dir(&(*t)->dir);
        rotacao_esq(t);
    }
}

void insert(avl_tree* t, char* x, bool* h) {
    if (*t == NULL) {
        *t = (avl_tree)malloc(sizeof(struct avl_no));
        if (!*t) {
            fprintf(stderr, "Erro de alocação de memória!\n");
            exit(1);
        }
        strcpy((*t)->dado.chave, x);
        (*t)->dado.cont = 1;
        (*t)->bal = 0;
        (*t)->esq = (*t)->dir = NULL;
        *h = true;
    } else {
        int cmp = strcasecmp(x, (*t)->dado.chave);
        if (cmp != 0) {
            if (cmp < 0)
                insert(&(*t)->esq, x, h);
            else
                insert(&(*t)->dir, x, h);

            if (*h) {
                if (cmp < 0) {
                    switch ((*t)->bal) {
                        case  1: (*t)->bal = 0; *h = false; break;
                        case  0: (*t)->bal = -1; break;
                        case -1: balance_esq(t); *h = false; break;
                    }
                } else {
                    switch ((*t)->bal) {
                        case -1: (*t)->bal = 0; *h = false; break;
                        case  0: (*t)->bal = 1; break;
                        case  1: balance_dir(t); *h = false; break;
                    }
                }
            }
        } else {
            (*t)->dado.cont++;
            *h = false;
        }
    }
}

void imprime(avl_tree t) {
    if (t != NULL) {
        imprime(t->esq);
        printf("%s (%d)\n", t->dado.chave, t->dado.cont);
        imprime(t->dir);
    }
}

avl_tree* getMin(avl_tree* t, bool* sucesso) {
    if (t == NULL || *t == NULL) {
        *sucesso = false;
        return NULL;
    }

    while ((*t)->esq != NULL) {
        t = &(*t)->esq;
    }

    *sucesso = true;
    return t;
}

int main() {
    avl_tree arvore = NULL;
    bool desbalanceado;

    insert(&arvore, "Pedro", &desbalanceado);
    insert(&arvore, "Guilherme", &desbalanceado);
    insert(&arvore, "Gabriela", &desbalanceado);
    insert(&arvore, "Camila", &desbalanceado);
    insert(&arvore, "Zoe", &desbalanceado);
    insert(&arvore, "Zezin", &desbalanceado);
    insert(&arvore, "lucas", &desbalanceado);
    insert(&arvore, "caique", &desbalanceado);
    
    
    bool sucesso;
    avl_tree* min = getMin(&arvore, &sucesso);
    if (sucesso) {
        printf("\nMenor chave: %s (%d)\n", (*min)->dado.chave, (*min)->dado.cont);
    } else {
        printf("\nÁrvore vazia.\n");
    }

    return 0;
}