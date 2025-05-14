#include <stdio.h>
#include <stdbool.h>

#define LIMITE 1000

typedef struct {
    int chegada, saida;
} Veiculo;

typedef struct {
    Veiculo dados[LIMITE];
    int topo;
} Pilha;

int main() {
    int total, capacidade, i;

    scanf("%d %d", &total, &capacidade);
    while (total != 0 || capacidade != 0) {
        
        Veiculo fila[total];
        for (i = 0; i < total; i++) {
            scanf("%d %d", &fila[i].chegada, &fila[i].saida);
        }

        Pilha estacionamento;
        estacionamento.topo = 0;
        bool valido = true;

        for (i = 0; i < total && valido; i++) {
            int entrada = fila[i].chegada;
            int retirada = fila[i].saida;

            // Retira veículos que já saíram
            while (estacionamento.topo > 0 && estacionamento.dados[estacionamento.topo - 1].saida <= entrada) {
                estacionamento.topo--;
            }

            // Checar se há vaga disponível
            if (estacionamento.topo == capacidade) {
                valido = false;
                break;
            }

            // Verifica a ordem de saída
            if (estacionamento.topo > 0 && retirada > estacionamento.dados[estacionamento.topo - 1].saida) {
                valido = false;
                break;
            }

            // Adiciona veículo ao estacionamento
            estacionamento.dados[estacionamento.topo++] = (Veiculo){entrada, retirada};
        }

        printf("%s\n", valido ? "Sim" : "Nao");
        scanf("%d %d", &total, &capacidade);
    }

    return 0;
}
