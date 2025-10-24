#include <iostream>

using namespace std;

// Função para imprimir os elementos de um array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Função de ordenação usando o Counting Sort
void countingSort(int arr[], int size) {
    // Se o array tiver 1 ou 0 elementos, já está ordenado
    if (size <= 1) {
        return;
    }

    // 1. Encontrar o maior elemento do array
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // 2. Criar um array de contagem de tamanho (max + 1) e inicializá-lo com zeros
    // Usamos alocação dinâmica para criar um array com tamanho variável
    int count[max + 1];
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // 3. Armazenar a contagem de cada elemento no array 'count'
    // O valor do elemento em 'arr' é usado como índice em 'count'
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // 4. Reconstruir o array original a partir do array de contagem
    int index = 0; // Índice para o array original 'arr'
    for (int i = 0; i <= max; i++) {
        // Para cada número 'i', enquanto sua contagem for maior que zero...
        while (count[i] > 0) {
            arr[index] = i; // ...adicione o número 'i' de volta ao array original
            index++;
            count[i]--; // ...e decremente sua contagem
        }
    }
    
    // Libera a memória alocada para o array de contagem
}

int main() {
    // Array com números repetidos e fora de ordem
    int arr[] = {4, 2, 8, 3, 2, 3, 1, 8, 4, 9, 1, 0};
    // Calcula o número de elementos no array
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original:" << endl;
    printArray(arr, n);

    // Chama a função de ordenação
    countingSort(arr, n);

    cout << "\nArray ordenado:" << endl;
    printArray(arr, n);

    return 0;
}
