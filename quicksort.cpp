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