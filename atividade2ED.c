#include <stdio.h>
#include <string.h>

int trocas = 0;
int comparacoes = 0;

void troca(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
    trocas++;
}

int dividir(char *arr[], int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        comparacoes++;
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    
    troca(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(char *arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = dividir(arr, low, high);
        
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    printf("Vetor Ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - ", arr[i]);
    }


    printf("\n\nTrocas: %d\n", trocas);
    printf("Comparacoes: %d\n", comparacoes);

    FILE *saida = fopen("saida.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(saida, "%s\n", arr[i]);
    }
    fclose(saida);

    char *mediana = arr[n / 2];
    printf("Mediana: %s\n", mediana);
}
