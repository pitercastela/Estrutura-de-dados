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
