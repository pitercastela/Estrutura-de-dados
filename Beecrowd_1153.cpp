#include <iostream>
using namespace std;

int fat(int x){
    if(x == 0)
        return 1;
    return x * fat(x-1);
}

int main()
{
    int N;
    cin >> N;
    cout << fat(N) << endl;
    return 0;
}
