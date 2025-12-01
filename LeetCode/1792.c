#include <stdio.h>
#include <stdlib.h>

// ------------------------------------------------------
// Estrutura que representa uma turma dentro do heap
// ------------------------------------------------------
typedef struct {
    int aprovados;
    int total;
    double ganho; // melhoria ao adicionar 1 aluno
} Turma;

// ------------------------------------------------------
// Calcula o ganho de porcentagem ao adicionar 1 aluno
// ------------------------------------------------------
double calcularGanho(int aprovados, int total) {
    double antes = (double)aprovados / total;
    double depois = (double)(aprovados + 1) / (total + 1);
    return depois - antes;
}

// ------------------------------------------------------
// Função para trocar dois elementos do heap
// ------------------------------------------------------
void trocar(Turma* a, Turma* b) {
    Turma aux = *a;
    *a = *b;
    *b = aux;
}

// ------------------------------------------------------
// Ajusta heap para baixo (heapify down)
// ------------------------------------------------------
void ajustarParaBaixo(Turma heap[], int indice, int tamanho) {
    int maior = indice;
    int esquerda = 2 * indice + 1;
    int direita  = 2 * indice + 2;

    if (esquerda < tamanho && heap[esquerda].ganho > heap[maior].ganho)
        maior = esquerda;

    if (direita < tamanho && heap[direita].ganho > heap[maior].ganho)
        maior = direita;

    if (maior != indice) {
        trocar(&heap[indice], &heap[maior]);
        ajustarParaBaixo(heap, maior, tamanho);
    }
}

// ------------------------------------------------------
// Ajusta heap para cima (heapify up)
// ------------------------------------------------------
void ajustarParaCima(Turma heap[], int indice) {
    int pai = (indice - 1) / 2;

    if (indice > 0 && heap[indice].ganho > heap[pai].ganho) {
        trocar(&heap[indice], &heap[pai]);
        ajustarParaCima(heap, pai);
    }
}

// ------------------------------------------------------
// Função exigida pelo LeetCode
// ------------------------------------------------------
double maxAverageRatio(int** turmas, int qtdTurmas, int* colSizes, int alunosExtras) {

    Turma* heap = malloc(qtdTurmas * sizeof(Turma));

    // Criar heap inicial
    for (int i = 0; i < qtdTurmas; i++) {
        heap[i].aprovados = turmas[i][0];
        heap[i].total = turmas[i][1];
        heap[i].ganho = calcularGanho(heap[i].aprovados, heap[i].total);
    }

    // Construir heap máximo
    for (int i = qtdTurmas / 2 - 1; i >= 0; i--)
        ajustarParaBaixo(heap, i, qtdTurmas);

    // Distribuir os alunos extras
    while (alunosExtras--) {

        // Melhor turma está no topo do heap
        Turma* t = &heap[0];

        t->aprovados++;
        t->total++;
        t->ganho = calcularGanho(t->aprovados, t->total);

        // Reorganizar heap
        ajustarParaBaixo(heap, 0, qtdTurmas);
    }

    // Calcular média final das porcentagens
    double soma = 0;
    for (int i = 0; i < qtdTurmas; i++)
        soma += (double)heap[i].aprovados / heap[i].total;

    free(heap);

    return soma / qtdTurmas;
}

// ------------------------------------------------------
// MAIN PARA TESTE
// ------------------------------------------------------
int main() {

    int qtdTurmas = 3;
    int colSizes[] = {2, 2, 2};

    // Alocar matriz dinamicamente
    int** turmas = malloc(qtdTurmas * sizeof(int*));
    for (int i = 0; i < qtdTurmas; i++)
        turmas[i] = malloc(2 * sizeof(int));

    // {aprovados, total}
    turmas[0][0] = 1; turmas[0][1] = 2;
    turmas[1][0] = 3; turmas[1][1] = 5;
    turmas[2][0] = 2; turmas[2][1] = 2;

    int alunosExtras = 2;

    double resposta = maxAverageRatio(turmas, qtdTurmas, colSizes, alunosExtras);

    printf("Resultado final = %.6f\n", resposta);

    return 0;
}
