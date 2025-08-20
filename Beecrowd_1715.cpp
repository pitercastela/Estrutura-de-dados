#include <iostream>
using namespace std;

int main() {
    int n,m;

    
    while (cin >> n >> m) {
        int goltodas = 0;

        for (int i = 0; i < n; ++i) {
            bool marcoutodas = true;

            for (int j = 0; j < m; ++j) {
                int gols;
                cin >> gols;

                
                if (gols == 0) {
                    marcoutodas = false;
                }
            }

            
            if (marcoutodas) {
                goltodas++;
            }
        }

        cout << goltodas << endl;
    }

    return 0;
}