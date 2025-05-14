#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para armazenar o nome e a assinatura de cada aluno
typedef struct {
    char nome[21];        // Nome do aluno (máximo 20 letras + '\0')
    char assinatura[101]; // Assinatura original do aluno (assumindo máximo 100 caracteres + '\0')
} Aluno;

// Função para calcular o número de diferenças entre duas strings (maiúscula/minúscula)
int calcularDiferencas(const char *original, const char *verificada) {
    int diferencas = 0;
    int tamanho = strlen(original);
    
    // Se os tamanhos forem diferentes, já consideramos uma diferença
    if (tamanho != strlen(verificada)) {
        return tamanho; // Retorna um valor maior que 1 para indicar falsificação
    }
    
    // Compara cada caractere
    for (int i = 0; i < tamanho; i++) {
        // Se os caracteres são diferentes, verifica se é apenas caso (maiúscula/minúscula)
        if (original[i] != verificada[i]) {
            // Se eles diferem apenas no caso, conta como uma diferença
            if ((original[i] >= 'a' && original[i] <= 'z' && original[i] - 32 == verificada[i]) ||
                (original[i] >= 'A' && original[i] <= 'Z' && original[i] + 32 == verificada[i])) {
                diferencas++;
            } else {
                // Se a diferença não é apenas no caso, é uma diferença mais significativa
                diferencas++;
            }
        }
    }
    
    return diferencas;
}

int main() {
    int n, m;
    
    // Loop principal para processar todos os casos de teste
    while (1) {
        scanf("%d", &n);
        
        // Condição de parada
        if (n == 0) {
            break;
        }
        
        // Aloca memória para armazenar os alunos e suas assinaturas originais
        Aluno *alunos = (Aluno *)malloc(n * sizeof(Aluno));
        if (alunos == NULL) {
            printf("Erro de alocação de memória\n");
            return 1;
        }
        
        // Lê os nomes e assinaturas originais dos alunos
        for (int i = 0; i < n; i++) {
            scanf("%s %s", alunos[i].nome, alunos[i].assinatura);
        }
        
        // Lê o número de alunos presentes na aula
        scanf("%d", &m);
        
        // Variáveis para processar as assinaturas da aula
        char nome[21];
        char assinatura_aula[101];
        int falsas = 0;
        
        // Processa cada assinatura da aula
        for (int i = 0; i < m; i++) {
            scanf("%s %s", nome, assinatura_aula);
            
            // Busca pelo aluno correspondente
            for (int j = 0; j < n; j++) {
                if (strcmp(nome, alunos[j].nome) == 0) {
                    // Encontrou o aluno, verifica a assinatura
                    int diferencas = calcularDiferencas(alunos[j].assinatura, assinatura_aula);
                    
                    // Se há mais de uma diferença, considera falsa
                    if (diferencas > 1) {
                        falsas++;
                    }
                    break;
                }
            }
        }
        
        // Imprime o resultado deste caso de teste
        printf("%d\n", falsas);
        
        // Libera a memória alocada para este caso de teste
        free(alunos);
    }
    
    return 0;
}