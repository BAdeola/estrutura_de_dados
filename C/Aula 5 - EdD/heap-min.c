#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TAM_MAX 6

void make_heap_min(int a[], int n) {
    int e = n/2, i, j, x, d = n-1; // índice do último 7
    while(e > 0) {
       e--; //3
       i = e; //3
       j = 2 * e + 1; // índice do filho esquerdo 7
       x = a[e]; // novo elemento 42
       if (j < d && a[j + 1] < a[j]) j++; 
       while (j <= d && a[j] < x) {
           a[i] = a[j];
           i = j;
           j = 2 * j + 1;
           if(j < d && a[j + 1] < a[j]) j++;
       }
       a[i] = x;
   }
}

int rem_heap_min(int a[], int * n) {
    if (*n == 1) {	
       return a[--(*n)];
    }
    int i = 0, j = 1; // índices do heap
    int menor = a[0], x, d;
    a[0] = a[--(*n)]; // passa o último para a raiz
    x = a[0]; // novo elemento
    d = *n-1; // índice do último
    if(j < d && a[j+1] < a[j]) j++; 
    while(j <= d && a[j] < x) {
        a[i] = a[j];
        i = j;
        j = 2 * j + 1;
        if(j < d && a[j+1] < a[j]) j++;
    }
    a[i] = x;
    return menor;
}

void ins_heap_min(int a[], int * n, int x) {
    int p, f;
    a[(*n)++] = x; // insere no final do heap
    p = *n-1; // índice do último
    f = (p - 1) / 2; // pai de p
    while (p > 0 && a[f] > x) {
       a[p] = a[f];
       p = f; 
       f = (p - 1) / 2;
    }
    a[p] = x;
 }

void mostra_vetor(int * v, int n){
    int i;

    for(i = 0; i < n; i++){
        printf("[%02d]", v[i]);
    }
    printf("\n");

}

int main(){

    int dados[TAM_MAX], i;

    srand(408);

    for(i = 0; i < TAM_MAX; i++){
        dados[i] = 1+(rand()%60);
    }

    mostra_vetor(dados, TAM_MAX);
    make_heap_min(dados, TAM_MAX);
    mostra_vetor(dados, TAM_MAX);


    return 0;
}