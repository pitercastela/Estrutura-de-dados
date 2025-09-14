#include <iostream>
#include <set>
using namespace std;

int main() {

    int aquant, bquant;

    while (cin >> aquant >> bquant && (aquant != 0 || bquant != 0)) {

        set<int> alicart;
        set<int> betcarts;

        for (int i = 0; i < aquant; ++i) {
            int cart;
            cin >> cart;
            alicart.insert(cart);
        }

        for (int i = 0; i < bquant; ++i) {
            int cart;
            cin >> cart;
            betcarts.insert(cart);
        }

        int alicepodtroc = 0;
        for (int cart : alicart) {
            if (betcarts.count(cart) == 0) {
                alicepodtroc++;
            }
        }

        int bettypodtroc = 0;
        for (int cart : betcarts) {
            if (alicart.count(cart) == 0) {
                bettypodtroc++;
            }
        }
        if (alicepodtroc < bettypodtroc)
        {
            cout << alicepodtroc << endl;
        }else if(alicepodtroc > bettypodtroc){
            cout << bettypodtroc << endl;
        } else{
            cout << alicepodtroc << endl;
        }

    }

    return 0;
}