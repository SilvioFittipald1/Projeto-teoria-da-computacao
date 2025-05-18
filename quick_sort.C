#include <stdio.h>

// Função de troca
void troca(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

// Função de partição (pivô é o primeiro elemento)
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

// Função principal do Quick Sort
void quick_sort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particao(v, inicio, fim);
        quick_sort(v, inicio, p - 1);
        quick_sort(v, p + 1, fim);
    }
}

// Função para imprimir vetor
void imprime(int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

// Exemplo de uso
int main() {
    int v[] = {9, 4, 6, 2, 8, 1, 3};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor original:\n");
    imprime(v, n);

    quick_sort(v, 0, n - 1);

    printf("Vetor ordenado:\n");
    imprime(v, n);

    return 0;
}
