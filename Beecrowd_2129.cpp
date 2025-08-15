#include <iostream>

using namespace std;

int fat(int x){
    if(x == 0)
        return 1;
    return x * fat(x-1);
}

int main(void) {
    int N, res, f, i = 10;
    cin >> N;
    f = fat(N);
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