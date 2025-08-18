#include <iostream>


using namespace std;

int main(void) {
    int divisor, dividendo, resto;
    cin >> dividendo >> divisor;
    resto = dividendo % divisor;
    cout << resto << endl;
}