#include <iostream>
using namespace std;

long long int fat(int x){
    if(x == 0)
        return 1;
    return x * fat(x-1);
}

int main()
{
    long long int N, M;

    while (cin >> N >> M)
    {
            cout << fat(N) + fat(M) << endl;
    }

    return 0;
}
