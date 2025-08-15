#include <iostream>
using namespace std;


int fibonot(int k){
    int fi1 = 1, fi2 = 2, fi3 = 3;
    while (k > 0){
        fi1 = fi2;
        fi2 = fi3;
        fi3 = fi1 + fi2;
        k -= (fi3 - fi2 - 1);
    }
    k += (fi3 - fi2 - 1);
    return fi2 + k;
}
int main(void) {
    int n;
    cin >> n;
    cout << fibonot(n) << endl;

}




// fi3 - fi2 -1 (calcula a quantidade de números entre os números de fibonacci)
// b + n (último número de fibonacci + o numero de casas q faltam)
