#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_PEQUENO 10000
#define TAMANHO_MEDIO   200000
#define TAMANHO_GRANDE  1000000

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

int main() {
    srand(time(NULL));

    int opcao, tamanho;
    const char *descricao;

    printf("Escolha o tamanho da entrada:\n");
    printf("1 - Pequena (%d elementos)\n", TAMANHO_PEQUENO);
    printf("2 - Media   (%d elementos)\n", TAMANHO_MEDIO);
    printf("3 - Grande  (%d elementos)\n", TAMANHO_GRANDE);
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            tamanho = TAMANHO_PEQUENO;
            descricao = "pequena";
            break;
        case 2:
            tamanho = TAMANHO_MEDIO;
            descricao = "media";
            break;
        case 3:
            tamanho = TAMANHO_GRANDE;
            descricao = "grande";
            break;
        default:
            printf("Opcao invalida.\n");
            return 1;
    }

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (!vetor) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    gerar_vetor(vetor, tamanho);

    printf("Ordenando vetor de entrada %s (%d elementos)...\n", descricao, tamanho);

    clock_t ini = clock();
    quick_sort(vetor, 0, tamanho - 1);
    clock_t fim = clock();

    double tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %.6f segundos\n", tempo);

    free(vetor);
    return 0;
}
