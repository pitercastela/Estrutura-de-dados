#include <iostream>
using namespace std;


int main() {
    int h1, m1, h2, m2;

    while (cin >> h1 >> m1 >> h2 >> m2 && (h1 != 0 || m1 != 0 || h2 != 0 || m2 != 0)) {

        int minini = h1 * 60 + m1;
        int minala = h2 * 60 + m2;

        int minsono;

        if (minala > minini) {
            minsono = minala - minini;
        } else {

            minsono = (24*60 - minini) + minala;
        }

        // Imprime o resultado
        cout << minsono << endl;
    }

    return 0;
}