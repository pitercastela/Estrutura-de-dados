#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, N;

    while (cin >> T >> N && T != 0) {

        int somapontos = 0;

        for (int i = 0; i < T; ++i) {
            string nometime;
            int pontostime;

            cin >> nometime >> pontostime;

            somapontos += pontostime;
        }

        int pontosmax = 3 * N;
        int numeroempates = pontosmax - somapontos;

        cout << numeroempates << endl;;
    }

    return 0;
}