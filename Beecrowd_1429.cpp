#include <iostream>
using namespace std;

int fat(int x){
    if(x == 0)
        return 1;
    return x * fat(x-1);
}

int main()
{
    int num, di1, di2, di3, di4, di5;

    while(true){

    cin >> num;
    if (num == 0)
        break;
    di1 = num % 10;
    num = num / 10;
    di2 = num % 10;
    num = num / 10;
    di3 = num % 10;
    num = num / 10;
    di4 = num % 10;
    num = num / 10;
    di5 = num % 10;

    cout << di1 * fat(1) + di2 * fat(2) + di3 * fat(3) + di4 * fat(4) + di5 * fat(5) << endl;
    }
}