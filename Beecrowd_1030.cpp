#include <iostream>
using namespace std;

int josephus(int n, int k) {
    int sobrevivente = 0;
    for (int i = 2; i <= n; ++i) {
        sobrevivente = (sobrevivente + k) % i;
    }

    // O resultado 'sobrevivente' está em base 0 (de 0 a n-1).
    // O problema pede em base 1 (de 1 a n), então somamos 1.
    return sobrevivente + 1;
}

int main() {

    int NC;
    cin >> NC;

    for (int i = 1; i <= NC; ++i) {
        int n, k;
        cin >> n >> k;

        int resultado = josephus(n, k);

        cout << "Case " << i << ": " << resultado << endl;
    }

    return 0;
}