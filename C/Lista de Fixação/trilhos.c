#include <stdio.h>

#define MAX_TAM 1000

int main() {
    int n;
    int sequencia_vagoes[MAX_TAM];

    while (scanf("%d", &n) && n != 0) {
        while (1) {
            scanf("%d", &sequencia_vagoes[0]);

            if (sequencia_vagoes[0] == 0) {
                printf("\n");
                break;
            }

            for (int i = 1; i < n; i++) {
                scanf("%d", &sequencia_vagoes[i]);
            }

            int pilha_estacao_vagoes[MAX_TAM], topo = -1;
            int prox_vagao = 1, indice_vagoes = 0;

            while (prox_vagao <= n) {
                pilha_estacao_vagoes[++topo] = prox_vagao++;

                while (topo >= 0 && pilha_estacao_vagoes[topo] == sequencia_vagoes[indice_vagoes]) {
                    topo--;
                    indice_vagoes++;
                }
            }

            if (topo == -1)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}