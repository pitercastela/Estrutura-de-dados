#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;

    while (cin >> N && N != 0) {

        string comandos;
        cin >> comandos;
        int direcao = 0;

        for (char comando : comandos) {
            if (comando == 'D') {
                direcao = (direcao + 1) % 4;
            } else {
                direcao = (direcao + 3) % 4;
            }
        }

        char saidas[] = {'N', 'L', 'S', 'O'};

        cout << saidas[direcao] << endl;
    }

    return 0;
}