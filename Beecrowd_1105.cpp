#include <iostream>
using namespace std;

int main() {
    int b, n;

    while (cin >> b >> n ) {
        if (b != 0 || n != 0)
        {
            break;
        }

        int res[21];

        for (int i = 1; i <= b; ++i) {
            cin >> res[i];
        }

        for (int i = 0; i < n; ++i) {
            int endiv, agi, val;
            cin >> endiv >> agi >> val;

            res[endiv] -= val;

            res[agi] += val;
        }

        bool resg = false;
        for (int i = 1; i <= b; ++i) {
            if (res[i] < 0) {
                resg = true;
            }
        }

        if (resg) {
            cout << "N" << endl;
        } else {
            cout << "S" << endl;
        }
    }
    return 0;
}