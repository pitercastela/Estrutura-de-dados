#include <iostream>
using namespace std;

int main() {
    int a, b;
    int lista[6] = {8,7,3,6,5,4};

    for (int i = 0; i < 6; i++){
    for (int i = 0; i < 5; i++){
        if (lista[i] > lista[i + 1]){
        a = lista[i];
        b = lista[i + 1];
        lista[i] = b;
        lista[i + 1] = a;
        }
    }
    }
    for(int i = 0; i < 6; i++){
        cout << lista[i] << endl;
    }

    return 0;
}