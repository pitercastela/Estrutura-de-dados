#include <iostream>
#include <iomanip>
using namespace std;



int main()
{
    float a,b,q;
    int i, t;
    
    while (true){
        cin >> t;
        i = 1;
        if (t == 0)
        break;
    while (t--){
        cin >> q >> a >> b;
        cout << "Size #" << i << ":" << endl;
        cout << "Ice Cream Used: " << fixed << setprecision(2) << (a+b)*q*5/2 << " cm2" << endl;
        i++;
    }
    cout << endl;
    }
    return 0;
}