#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    long long andares[n];

    for (int i = 0; i < n; ++i) {
        cin >> andares[i];
    }

    long long max = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long dist = andares[i] + andares[j] + (j - i);
            
            if (dist > max)
            max = dist;
        }
    }

    cout << max << endl;

    return 0;
}
