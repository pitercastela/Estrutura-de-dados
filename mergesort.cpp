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

void merge(vector<int>& arr, int esq, int dir, int meio) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    vector<int> e(n1);
    vector<int> d(n2);

    for (int i = 0; i < n1; i++) {
        e[i] = arr[esq + i];
    }
    for (int i = 0; i < n2; i++) {
        d[i] = arr[meio + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = esq;

    while (i < n1 && j < n2) {
        if (e[i] <= d[j]) {
            arr[k] = e[i];
            i++;
        } else {
            arr[k] = d[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = e[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = d[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int esq, int dir) {
    int meio = (esq + dir)/ 2;
    if (esq >= dir) {
        return;
    }


    mergeSort(arr, esq, meio);
    mergeSort(arr, meio + 1, dir);

    merge(arr, esq, dir, meio);
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10, 2, 7, 10, 25, 67};

    cout << "Array original: " << endl;
    printVector(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Array ordenado: " << endl;


    
    printVector(arr);

    return 0;
}
*/

//versão array

#include <iostream>

// Função para imprimir os elementos de um array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Função para mesclar duas sub-arrays ordenadas
void merge(int arr[], int esq, int dir, int meio) {
    // Calcula o tamanho das duas sub-arrays a serem mescladas
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    // Cria arrays temporários para armazenar os dados
    int e[n1]; // Array da esquerda
    int d[n2]; // Array da direita

    // Copia os dados para os arrays temporários e[] e d[]
    for (int i = 0; i < n1; i++) {
        e[i] = arr[esq + i];
    }
    for (int i = 0; i < n2; i++) {
        d[i] = arr[meio + 1 + i];
    }

    // Índices iniciais para as sub-arrays e para a array mesclada
    int i = 0; 
    int j = 0; 
    int k = esq; 

    // Mescla os arrays temporários de volta em arr[esq...dir]
    while (i < n1 && j < n2) {
        if (e[i] <= d[j]) {
            arr[k] = e[i];
            i++;
        } else {
            arr[k] = d[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de e[], se houver
    while (i < n1) {
        arr[k] = e[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de d[], se houver
    while (j < n2) {
        arr[k] = d[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort que divide o array e chama a função merge
void mergeSort(int arr[], int esq, int dir) {
    // Condição de parada da recursão
    if (esq >= dir) {
        return;
    }

    int meio = (esq + dir) / 2;

    // Ordena a primeira e a segunda metade
    mergeSort(arr, esq, meio);
    mergeSort(arr, meio + 1, dir);

    // Mescla as duas metades ordenadas
    merge(arr, esq, dir, meio);
}

int main() {
    // Declara um array C-style
    int arr[] = {38, 27, 43, 3, 9, 82, 10, 2, 7, 10, 25, 67};
    // Calcula o número de elementos no array
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: " << std::endl;
    printArray(arr, n);

    // Chama a função de ordenação
    mergeSort(arr, 0, n - 1);

    std::cout << "Array ordenado: " << std::endl;
    printArray(arr, n);

    return 0;
}
