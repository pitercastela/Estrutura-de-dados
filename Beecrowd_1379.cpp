#include <iostream>
using namespace std;

int calcula (int a, int b){
    return a*2 - b;
}

int main()
{
    int a, b ,c;

    while (true)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        cout << calcula(a,b) << endl;
    }




    return 0;
}

