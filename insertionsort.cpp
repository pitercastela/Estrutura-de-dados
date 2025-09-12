#include <iostream>
using namespace std;

int main() {
    int meio, menos;
    int lista[6] = {8,8,3,6,5,4};

    for (int j = 0; j < 6; j++){
    for (int i = j; i > 0; i--){
        if (lista[i - 1] > lista[i]){
        meio = lista[i];
        lista[i] = lista[i - 1];
        lista[i - 1] = meio;
        }
    }
    }
    for(int i = 0; i < 6; i++){
        cout << lista[i] << endl;
    }

    return 0;
}