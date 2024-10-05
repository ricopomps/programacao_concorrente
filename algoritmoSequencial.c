#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100000

void bubbleSort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int *arr = (int*) malloc(TAMANHO * sizeof(int));
    clock_t inicio, fim;
    double tempo;

    // Inicializa o array com valores aleatórios
    srand(time(NULL));
    for (int i = 0; i < TAMANHO; i++) {
        arr[i] = rand() % 10000;
    }

    // Algoritmo Serial
    inicio = clock();
    bubbleSort(arr, TAMANHO);
    fim = clock();

    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo Serial: %f segundos\n", tempo);

    free(arr);
    return 0;
}
