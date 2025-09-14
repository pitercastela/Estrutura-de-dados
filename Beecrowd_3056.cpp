#include <iostream>
using namespace std;

int main() {
    long long n;


    while (cin >> n) {
        long long num;
        for (int i=0; i < n; i++){
        num *= 2;
    }
        cout << (num+1)*(num+1) << endl;;
    }

    return 0;
}