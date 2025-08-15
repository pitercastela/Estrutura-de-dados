#include <iostream>

using namespace std;

int main(void) {
    int num, seg, temp, r;
    int i, j;
    int listac[1000], listaf[1000];

    while (cin >> num && num != 0) {
        for (int i = 0; i  <  num; ++i) {
            cin >> listac[i];
            listaf[i] = listac[i];
        }
        for (int i = 0; i  <  num-1; ++i)
            for (int j = i+1; j  <  num; ++j)
                if (listaf[i] > listaf[j]) {
                    temp = listaf[i];
                    listaf[i] = listaf[j];
                    listaf[j] = temp;
                }
        seg = listaf[num-2];
        for (int i = 0; i  <  num; ++i)
            if (seg == listac[i])
                r = i + 1;
        cout << r << endl;
    }
    return 0;
}