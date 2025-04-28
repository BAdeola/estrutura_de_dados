#ifndef ARVORE_H_
#define ARVORE_H_

typedef struct s_no{
    int dado;
    struct s_no * esq, * dir;
} no;

void insere_ordenado( no arvore[], int posicao_vetor, int valor,  no * pai);
void print_pre(no *no);
void print_in(no* no);
void print_post(no* no);

#endif