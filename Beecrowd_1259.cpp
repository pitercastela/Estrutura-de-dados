#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> pares;
    vector<int> impares;

    for (int i = 0; i < N; ++i) {
        int numero;
        cin >> numero;

        if (numero % 2 == 0) {
            pares.push_back(numero);
        } else {
            impares.push_back(numero);
        }
    }

    sort(pares.begin(), pares.end());

    sort(impares.begin(), impares.end());
    reverse(impares.begin(), impares.end());

    for (int par : pares) {
        cout << par << endl;
    }

    for (int impar : impares) {
        cout << impar << endl;
    }

    return 0;
}