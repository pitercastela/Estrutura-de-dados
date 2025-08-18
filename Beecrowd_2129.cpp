#include <iostream>

using namespace std;

long long int fatorial[10001];


long long int fat(int x){
    if(x == 0){
        fatorial[x] = 1;
        return fatorial[x];
    }
    fatorial[x] = x * fat(x-1);
    return fatorial[x];
}

int main(void) {
    fat(1000000);
    int N, res, f, i;
    while (cin >> N)
    {
        i = 10;
            f = fatorial[N];
    while (true)
    {
        if (f % i != 0){
            break;
        }
        i *=10;
    }

    res = (f % i) / (i/10);

    cout << res << endl;
    }



}