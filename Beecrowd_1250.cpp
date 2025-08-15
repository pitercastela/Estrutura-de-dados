#include <iostream>
#include <cstdio>
using namespace std;

int main()
{

    string str = "geeksforgeeks";

    const int n = str.length();


    char arr[n + 1];


    strcpy(arr, str.c_str());
    return 0;
}

