#include <iostream>
using namespace std;

    double i;
    int caso = 1;
long long int fibo(int x){
    if (x == 0){
        i += 1;
        return 0;
    }

    if (x == 1){
        i += 1;
        return 1;
    }
    i += 1;
    return fibo(x - 1) + fibo(x - 2);

}

int main()
{

    int M, N, k;

    k = M;

    while (true)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        i = 0;

        int R = fibo(N);
        cout << "Case " << caso << ": " << N << " " << M << " " << i/M << endl;
    }

    return 0;
}