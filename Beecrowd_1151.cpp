#include <iostream>
using namespace std;


long long int fibonacci[100000];

long long int fibo(int x){
    if (fibonacci[x] != -1) {
        return fibonacci[x];
    }
    if (x == 0){
    fibonacci[x] = 0;
        return fibonacci[x];
    }
    if (x == 1){
        fibonacci[x] = 1;
        return fibonacci[x];
    }
    fibonacci[x] = fibo(x - 1) + fibo(x - 2);
    return fibonacci[x];

}
    void inicializaVetor(){
        for (int i = 0; i < 100000; i++){
            fibonacci[i] = -1;
        }
    }
int main()
{
    inicializaVetor();

    fibo(10000);
    int N;
    cin >> N;

    for (int i = 0; i <= N; i++) {
        if (i = N) {
            cout << fibonacci[i] << endl;
            break;
        }
        cout << fibonacci[i] << " ";
    }

    return 0;
}