#include <iostream>

using namespace std;

int fat(int x){
    if(x == 0)
        return 1;
    return x * fat(x-1);
}

int main(void) {
   int num, c, quo, f;
   cin >> num;
   c = 0;
   for (int i = 8; i >= 0; --i) {
      f = fat(i);

      quo = int(num / f);

      num -= quo * f;

      c += quo;

      //cout << f << " " << quo << " " << num << " " << c << " " << endl;
   }
   cout << c << endl;
   return 0;
}