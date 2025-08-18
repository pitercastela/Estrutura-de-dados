#include <iostream>

using namespace std;

int main() {
    int i;
    cin >> i;

    if (i == 1)
    cout << "Top 1" << endl;
    else if (i <= 3)
    cout << "Top 3" << endl;
    else if (i <= 5)
    cout << "Top 5" << endl;
    else if (i <= 10)
    cout << "Top 10" << endl;
    else if (i <= 25)
    cout << "Top 25" << endl;
    else if (i <= 50)
    cout << "Top 50" << endl;
    else if (i <= 100)
    cout << "Top 100" << endl;


    return 0;
}