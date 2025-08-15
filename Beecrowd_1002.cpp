#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;


int main(){
    double x;
    double n = 3.14159;
   
    cin >> x;

    printf("A=%.4f\n", n * x * x);
    cout << fixed << setprecision(4) << x << endl;

    return 0;
}
