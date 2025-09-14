#include <iostream>
using namespace std;

void trocar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {

    int N, Q;
    cin >> N >> Q;


    int mesas[N + 1];


    for (int i = 1; i <= N; ++i) {
        mesas[i] = i;
    }

    for (int i = 0; i < Q; ++i) {
        int tipo_evento;
        cin >> tipo_evento;

        if (tipo_evento == 1) {
            int mesaA, mesaB;
            cin >> mesaA >> mesaB;
            trocar(mesas[mesaA], mesas[mesaB]);

        } else {
            int funcionario_procurado;
            cin >> funcionario_procurado;

            int redirecionamentos = 0;
            int mesa_atual = funcionario_procurado;

            while (mesas[mesa_atual] != funcionario_procurado) {
                redirecionamentos++;
                mesa_atual = mesas[mesa_atual];
            }

            cout << redirecionamentos << endl;
        }
    }

    return 0;
}