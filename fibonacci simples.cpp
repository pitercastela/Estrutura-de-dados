#include <iostream>
using namespace std;



long long int fibo(int x){
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    return fibo(x - 1) + fibo(x - 2);

}

int main()
{

    int M, N;
    cin >> M;

    while (M--)
    {
        cout << "Informe o número" << endl;
        cin >> N;
        cout << fibo(N) << endl;
    }
    
    return 0;
}
