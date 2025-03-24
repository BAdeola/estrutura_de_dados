#include "pilhas.h"
#define NOME_ARQ "C:\\Users\\braya\\OneDrive\\Área de Trabalho\\estruturaDeDadosEmC\\Unisantos Aula\\Aula 3 - EdD\\pilhas\\teste.c"
#include <stdio.h>

///: inicializa a pilha p no estado vazio
void stack_init(pilha * p){
    p->topo = 0;
}

///: insere o elemento x no topo da pilha p
bool push(pilha * p, t_dado x){
    if(p->topo == MAX_TAM){
        return false;
    }

     p->itens[p->topo++] = x;

     return true;
}
///: remove e devolve o elemento do topo da pilha p
bool pop(pilha * p, t_dado * r){
    if (p->topo == 0)
        return false;

    *r = p->itens[--p->topo];
    return true;
}
///: acessa o elemento do topo da pilha p devolvendo uma c�pia do seu valor
bool top(pilha p, t_dado * topo){
    if (p.topo == 0)
        return false;
    *topo = p.itens[p.topo - 1];
    return true;
}
///: devolve verdadeiro se a pilha p estiver vazia e falso, caso contr�rio
bool stack_isempty(pilha p){
    return p.topo == 0;

}
///: devolve verdadeiro se a pilha p estiver cheia e falso, caso contr�rio
bool stack_isfull(pilha p){
    return p.topo == MAX_TAM;
}

void exercicio1() {

    pilha p;
    stack_init(&p);
    char word[MAX_TAM] = "rayda";
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        push(&p, word[i]);
    }

    char c;
    while(!stack_isempty(p)){
        pop(&p, &c);
        printf("%c",c);
    }
}

void exercicio2(){

    pilha p;
    stack_init(&p);

    FILE* arq;
    if ((arq = fopen(NOME_ARQ, "r")) == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char c, aux;
    int lin = 1, col = 1;
    while ((c = fgetc(arq)) != EOF) {
        printf("%c", c);
        if (c == '\n') {
            lin++;
            col = 1;
        }
        else col++;
        switch (c) {
            case '{': case '[': case '(':
                push(&p, c);
                break;
            case '}': case ']': case ')':
                if (!top(p, &aux)) {
                    print_erro(lin, col);
                }
                if (casar_delimitador(aux, c)) {
                    pop(&p, &c);
                }
        }
    }

    if (p.topo != 0) {
        print_erro(lin, col);
    }

}



void exercicio3(){

    pilha p1, p2;
    stack_init(&p1);
    stack_init(&p2);

    int num;
    while(!stack_isfull(p1)) {
        scanf("%d", &num);
        push(&p1, num);
    }

    int i, impar=0;
    for (i=1; i<=MAX_TAM; i++){
        pop(&p1, &num);
        if(num%2==0){
            push(&p2, num);
        } else {
            impar++;
        }
    }

    while(!stack_isempty(p2)) {
        pop(&p2, &num);
        printf("%d ", num);
    }

    printf("\n");
    printf("%d", impar);

}


void exercicio4(){

    pilha p1, p2;
    stack_init(&p1);
    stack_init(&p2);


    int num;
    while(!stack_isfull(p1)) {
        scanf("%d", &num);
        push(&p1, num);
    }

    while(!stack_isempty(p1)) {
        pop(&p1, &num);
        push(&p2, num);

    }

    while(!stack_isempty(p2)) {
        pop(&p2, &num);
        printf("%d ", num);
    }
}

void exercicio5() {

    pilha p;
    stack_init(&p);

    int num;

    while(!stack_isfull(p)) {
        scanf("%d", &num);
        push(&p, num);
    }

    printf("A pilha esta cheia.\n");
}


void exercicio6() {

    pilha p;
    stack_init(&p);

    int num;
    printf("\n");

    while(!stack_isfull(p)) {
        scanf("%d", &num);
        push(&p, num);

    }

    int c;
    while(!stack_isempty(p)){
        pop(&p, &c);
        printf("%d ",c);
    }

}

void exercicio7() {

    pilha p1;
    pilha p2;
    stack_init(&p1);
    stack_init(&p2);

    int i, num;
    for (i=1; i <=4; i++) {
        num = i;
        push(&p1, num);
    }

    for (i=1; i <=8; i++) {
        num = i;
        push(&p2, num);
    }

    int cont1=0, cont2=0;
    while(!stack_isempty(p1)){
        pop(&p1, &num);
        cont1++;
    }

    while(!stack_isempty(p2)){
        pop(&p1, &num);
        cont2++;
    }

    if(cont1>cont2){
        printf("A pilha 1 é a com mais elementos, %d", cont1);
    } else if (cont1 == cont2) {
        printf("As duas pilhas possuem o mesmo valor, %d", cont1);
    } else{
        printf("A pilha 2 é com mais elementos, %d", cont2);
    }
}


