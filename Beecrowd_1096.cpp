#include <iostream>

using namespace std;

int main() {
    int i = 1,j;

    while (true){
        j = 7;
        if (i == 11){
            break;}

            while (true)
            {
                if (j == 4)
                    break;
                cout << "I=" << i << " J=" << j << endl;
                j--;
            }


        i = i+2;
    }

    return 0;
}