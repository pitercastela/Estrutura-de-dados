#include <iostream>
using namespace std;

int main()
{
    int n, r, p = 0, np = 0;
    cin >> n;
    while (n--){
        cin >> r;
        if (r == 0){
            p += 1;
        } else if (r == 1){
            np += 1;
        }
    }
    if(p > np){
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }
    
    return 0;
}