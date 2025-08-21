#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;


int main(int argc, char* argv[]) {
    int len = argc - 1;
    int sum = 0;
    for (int i=1; i<=len; i++)   {
        sum = sum + stoi(argv[i]);
    }
    cout << sum;
}