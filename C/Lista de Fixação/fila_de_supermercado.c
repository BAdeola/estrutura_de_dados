#include <stdio.h>
#include <stdlib.h>

#define MAX 10005

typedef struct {
    long long tempo; // tempo em que o funcionário estará livre
    int id;          // id do funcionário
} Funcionario;

//essa função compara os funcionarios, quem estiver com o menor tempo é retornado, caso o tempo seja igual, retorna o com menor id
int comparacao(const void *a, const void *b) {
    Funcionario *f1 = (Funcionario *)a;
    Funcionario *f2 = (Funcionario *)b;
    if (f1->tempo == f2->tempo) {
        return f1->id - f2->id; //menor id tem prioridade
    }

    return f1->tempo - f2->tempo; //menor tempo tem prioridade
}

Funcionario heap[MAX]; //vetor global que simula uma heap, terá o valor de N
int heapSize = 0; //quantos elementos estão na heap

//função de push na heap criada acima
void pushHeap(Funcionario f) {
    heap[heapSize++] = f; // adiciona no fim
    int i = heapSize - 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (comparacao(&heap[i], &heap[p]) < 0) {
            Funcionario temp = heap[i];
            heap[i] = heap[p];
            heap[p] = temp;
            i = p;
        } else break;
    }
}

//função de pop de heap, retirar o elemento
Funcionario popHeap() {
    Funcionario top = heap[0]; // pega o menor (topo da heap)
    heap[0] = heap[--heapSize]; // substitui pelo último
    int i = 0;
    while (1) { //todo esse while ordena a heap, é uma sift down, uma forma de organizar a heap em O(log n)
        int l = 2 * i + 1, r = 2 * i + 2, menor = i;
        if (l < heapSize && comparacao(&heap[l], &heap[menor]) < 0) menor = l;
        if (r < heapSize && comparacao(&heap[r], &heap[menor]) < 0) menor = r;
        if (menor != i) {
            Funcionario temp = heap[i];
            heap[i] = heap[menor];
            heap[menor] = temp;
            i = menor;
        } else break;
    }

    return top;
}



int main(){
    int N, M;
    int vi[MAX], cj[MAX];

    //lê N (funcionários) e M (clientes)
    scanf("%d %d", &N, &M);

    //lê os tempos por item (vi) de cada funcionário
    for (int i = 0; i < N; i++) {
        scanf("%d", &vi[i]);
    }

    //lê quantos itens cada cliente possui (cj)
    for (int i = 0; i < M; i++) {
        scanf("%d", &cj[i]);
    }

    //adiciona todos os funcionários na heap, inicialmente com tempo 0
    heapSize = 0;
    for (int i = 0; i < N; i++) {
        Funcionario f = {0, i}; // tempo inicial 0
        pushHeap(f);
    }

    //simulação do atendimento
    long long tempoFinal = 0;
    for (int i = 0; i < M; i++) {
        Funcionario f = popHeap(); //pego o funcionário mais livre da heap
        long long tempoAtendimento = (long long)vi[f.id] * cj[i]; //calculo quanto tempo ele levará com esse cliente
        f.tempo += tempoAtendimento; //atualiza o tempo total em que o funcionário vai ficar livre
        if (f.tempo > tempoFinal) tempoFinal = f.tempo; //atualiza tempoFinal, somente se esse for o maior tempo até agora
        pushHeap(f); //da push no funcionário de volta na heap com o novo tempo
    }

    printf("%lld\n", tempoFinal); //printa o resultado
    return 0;
}