/*
#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}
int temp;


int dividir(vector<int>& arr, int men, int max) {
    int pivo = arr[men];

    int esq = men + 1;
    int dir = max;

    while (true) {
        while (esq <= dir && arr[esq] <= pivo) {
            esq++;
        }
        while (dir >= esq && arr[dir] > pivo) {
            dir--;
        }

        if (esq > dir) {
            break;
        }

        temp = arr[esq];
        arr[esq] = arr[dir];
        arr[dir] = temp;
    }

        temp = arr[men];
        arr[men] = arr[dir];
        arr[dir] = temp;

    return dir;
}

void quickSort(vector<int>& arr, int men, int max) {
    if (men < max) {
        int meio = dividir(arr, men, max);

        quickSort(arr, men, meio - 1);
        quickSort(arr, meio + 1, max);
    }
}

int main() {
    vector<int> arr = {90, 7, 8, 9, 1, 50, 4};

    cout << "Array original (pivô será o 90):" << endl;
    printVector(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "\nArray ordenado:" << endl;
    printVector(arr);

    return 0;

}
*/

//versão com array

#include <iostream>

// Função para imprimir os elementos de um array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Função para particionar o array e retornar o índice do pivô
int dividir(int arr[], int men, int max) {
    int pivo = arr[men];
    int esq = men + 1;
    int dir = max;
    int temp; // Variável para troca (swap)

    while (true) {
        // Encontra um elemento à esquerda que é maior que o pivô
        while (esq <= dir && arr[esq] <= pivo) {
            esq++;
        }
        // Encontra um elemento à direita que é menor ou igual ao pivô
        while (dir >= esq && arr[dir] > pivo) {
            dir--;
        }

        // Se os ponteiros se cruzaram, a partição está completa
        if (esq > dir) {
            break;
        }

        // Troca os elementos encontrados
        temp = arr[esq];
        arr[esq] = arr[dir];
        arr[dir] = temp;
    }

    // Coloca o pivô em sua posição final correta
    temp = arr[men];
    arr[men] = arr[dir];
    arr[dir] = temp;

    return dir; // Retorna o índice do pivô
}

// Função principal do Quick Sort
void quickSort(int arr[], int men, int max) {
    if (men < max) {
        // Encontra o ponto de divisão (pivô)
        int meio = dividir(arr, men, max);

        // Ordena recursivamente os elementos antes e depois da partição
        quickSort(arr, men, meio - 1);
        quickSort(arr, meio + 1, max);
    }
}

int main() {
    // Declara um array C-style
    int arr[] = {90, 7, 8, 9, 1, 50, 4};
    // Calcula o número de elementos no array
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original (pivô será o 90):" << std::endl;
    printArray(arr, n);

    // Chama a função de ordenação
    quickSort(arr, 0, n - 1);

    std::cout << "\nArray ordenado:" << std::endl;
    printArray(arr, n);

    return 0;
}
