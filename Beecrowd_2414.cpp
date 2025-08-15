#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int num, maior = 0;
    vector<int> listan;

    while (true) {
        cin >> num;
        if (num == 0){
            break;
    }
        listan.push_back(num);
}
    for (int i : listan){
        if (i > maior)
            maior = i;
    }
    cout << maior << endl;
    return 0;
}