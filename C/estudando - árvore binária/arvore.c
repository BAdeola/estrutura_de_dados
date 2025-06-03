#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int conteudo;
    struct No *esquerda, *direita;
} No;

typedef struct Arvore {
    No *raiz;
} Arvore;

// Função auxiliar recursiva para inserir um valor na árvore
No* inserirNo(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }

    if (valor < raiz->conteudo) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else if (valor > raiz->conteudo) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }

    return raiz;
}

// Função pública de inserção
void inserir(Arvore *arv, int valor) {
    arv->raiz = inserirNo(arv->raiz, valor);
}

// Impressão in-order (esquerda, raiz, direita)
void impressao(No *raiz) {
    if (raiz != NULL) {
        impressao(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        impressao(raiz->direita);
    }
}

int tamanho(No * raiz){
    if (raiz == NULL)
        return 0;
    else
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

int buscar(No *raiz, int chave){
    if(raiz == NULL) {
        return -1;
    } else {
        if (raiz->conteudo == chave) {
            return raiz->conteudo;
        } else {
            if (chave < raiz->conteudo){
                return buscar(raiz->esquerda, chave);
            } else {
                return buscar(raiz->direita, chave);
            }
        }
    }
}

int main() {
    int op, valor;
    Arvore arv;
    arv.raiz = NULL;

    do {
        printf("\n0 - sair\n1 - inserir\n2 - imprimir\n3-buscar\n");
        scanf("%d", &op);

        switch (op) {
        case 0:
            printf("Saindo...");
            break;
        case 1:
            printf("\nDigite um valor: ");
            scanf("%d", &valor);
            inserir(&arv, valor);
            break;
        case 2:
            printf("\nImpressão da árvore binária:\n");
            impressao(arv.raiz);
            printf("\nTamanho: %d\n", tamanho(arv.raiz));
            break;
        case 3:
            printf("\nQual valor deseja buscar?\n");
            scanf("%d", &valor);
            printf("\nResultado da busca: %d", buscar(arv.raiz, valor));
            break;
        default:
            printf("Opção Inválida!");
            break;
        }
    } while (op != 0);

    return 0;
}