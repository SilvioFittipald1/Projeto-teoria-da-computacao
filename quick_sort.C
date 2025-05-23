#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAMANHO_PEQUENO 10000
#define TAMANHO_MEDIO   200000
#define TAMANHO_GRANDE  1000000
#define REPETICOES 30

void gerar_vetor(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 1000000;
    }
}

void troca(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int particao(int v[], int inicio, int fim) {
    int pivot = inicio;
    int indice = fim;

    for (int i = fim; i > inicio; i--) {
        if (v[i] >= v[pivot]) {
            troca(v, i, indice);
            indice--;
        }
    }

    troca(v, pivot, indice);
    return indice;
}

void quick_sort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particao(v, inicio, fim);
        quick_sort(v, inicio, p - 1);
        quick_sort(v, p + 1, fim);
    }
}

double calcular_media(double tempos[], int n) {
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += tempos[i];
    }
    return soma / n;
}

double calcular_desvio(double tempos[], int n, double media) {
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += pow(tempos[i] - media, 2);
    }
    return sqrt(soma / n);
}

void testar_quick_sort(int tamanho, const char *descricao) {
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (!vetor) {
        printf("Erro de alocação para tamanho %s (%d elementos)\n", descricao, tamanho);
        return;
    }

    double tempos[REPETICOES];
    double tempo_total = 0.0;

    printf("===== Testando entrada %s (%d elementos) =====\n", descricao, tamanho);

    for (int i = 0; i < REPETICOES; i++) {
        gerar_vetor(vetor, tamanho);

        clock_t ini = clock();
        quick_sort(vetor, 0, tamanho - 1);
        clock_t fim = clock();

        double tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
        tempos[i] = tempo;
        tempo_total += tempo;

        printf("Execucao %02d concluida em %.4f segundos.\n", i + 1, tempo);
    }

    double media = calcular_media(tempos, REPETICOES);
    double desvio = calcular_desvio(tempos, REPETICOES, media);

    printf("\nTempo TOTAL: %.6f segundos\n", tempo_total);
    printf("Tempo medio: %.6f segundos\n", media);
    printf("Desvio padrao: %.6f\n", desvio);
    printf("===============================================\n\n");

    free(vetor);
}

int main() {
    srand(time(NULL));

    testar_quick_sort(TAMANHO_PEQUENO, "pequena");
    testar_quick_sort(TAMANHO_MEDIO, "media");
    testar_quick_sort(TAMANHO_GRANDE, "grande");

    return 0;
}
