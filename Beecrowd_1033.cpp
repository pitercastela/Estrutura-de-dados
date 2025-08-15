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
    cin >> M;
    k = M;

    while (true)
    {   
        if (M == 0 && N == 0) 
            break;
        
        i = 0;
        cin >> N;
        int R = fibo(N);
        cout << "Case " << caso << ": " << M << " " << N << " " << i/N << endl;
    }
    
    return 0;
}