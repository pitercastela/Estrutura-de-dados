#include <iostream>
using namespace std;

int fat(int x){
    if(x == 0)
        return 1;
    return x * fat(x-1);
}

int main()
{
    int M;
    cin >> M;
    while (M--)
    cout << "informe o número" << endl;
    int N;
    cin >> N;
    cout << fat(N) << endl;
    return 0;
}
