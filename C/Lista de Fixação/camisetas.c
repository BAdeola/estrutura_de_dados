#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct Camiseta
{
    char nome[100], cor[10], tamanho[10];  // Estrutura que define uma camiseta
};

// Função de comparação usada no qsort
int comp(const void *a, const void *b)
{
    struct Camiseta *cA = (struct Camiseta *)a;  // Cast para o tipo Camiseta
    struct Camiseta *cB = (struct Camiseta *)b;  // Cast para o tipo Camiseta

    // Primeiro, comparamos a cor das camisetas
    if (strcmp(cA->cor, cB->cor) == 0)
    {
        // Se as cores forem iguais, comparamos o tamanho
        if (strcmp(cA->tamanho, cB->tamanho) == 0)
        {
            // Se o tamanho também for igual, comparamos o nome dos alunos
            return strcmp(cA->nome, cB->nome);
        }
        // Se o tamanho for diferente, fazemos a comparação em ordem decrescente (G > M > P)
        return -strcmp(cA->tamanho, cB->tamanho);
    }
    // Caso as cores sejam diferentes, comparamos a cor em ordem crescente
    return strcmp(cA->cor, cB->cor);
}

int main()
{
    int N, first;  // N é o número de camisetas e first controla a linha em branco entre os casos
    struct Camiseta camisetas[60];  // Vetor de camisetas (suporta até 60 camisetas por caso)

    first = 1;  // Inicializa o flag 'first' para controlar a linha em branco
    while (scanf("%d\n", &N))  // Lê o número de camisetas para o caso de teste
    {
        // Se N for 0, significa o final da entrada (condição de parada)
        if (!N)
            break;

        // Imprime uma linha em branco entre os casos, mas não no primeiro caso
        if (first)
            first = 0;
        else
            printf("\n");

        // Lê as camisetas
        for (int i = 0; i < N; ++i)
        {
            // Lê o nome do estudante (utilizando %[^] para ler até o final da linha)
            scanf("%[^\n]\n", &(camisetas[i].nome));
            // Lê a cor e o tamanho da camiseta
            scanf("%s %s\n", &(camisetas[i].cor), &(camisetas[i].tamanho));
        }

        // Ordena o vetor de camisetas utilizando qsort e a função de comparação 'comp'
        qsort(camisetas, N, sizeof(struct Camiseta), comp);

        // Imprime as camisetas ordenadas
        for (int i = 0; i < N; ++i)
        {
            // Formato de saída: cor, tamanho, nome
            printf("%s %s %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);
        }
    }

    return 0;  // Fim do programa
}