#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> asciis;
    string test = "Hello world";
    cout << test << endl;
    for (int i=0; i < 10; i++) {
        asciis.push_back(int(test[i]));
    }
    for (int i=0; i < 11; i++) {
        cout << asciis[i] << endl;
    }
}