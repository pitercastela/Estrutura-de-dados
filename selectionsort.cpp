#include <iostream>
using namespace std;

int main() {
    int menora, b, ini;
    ini = 0;
    int lista[6] = {8,8,3,6,5,4};
    menora = 0;

    for (int j = 0; j < 6; j++){
        menora = ini;
    for (int i = ini; i < 6; i++){
        if (lista[menora] > lista[i]){
        menora = i;
        }
    }
        b = lista[j];
        lista[j] = lista[menora];
        lista[menora] = b;
        ini += 1;
    }
    for(int i = 0; i < 6; i++){
        cout << lista[i] << endl;
    }

    return 0;
}