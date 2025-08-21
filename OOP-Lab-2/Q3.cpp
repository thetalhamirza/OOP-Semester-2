#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;


int push(int val, int *array, int topPointer) {

    topPointer++;
    array[topPointer] = val;


}



int main() {

    int *arrNum = new int[5];
    int topPointer = -1;
    char entry = 0;

    while (true) {


        cout << "Enter value to enter: ";
        cin >> entry;
        int updated = push(entry, arrNum, topPointer);

        // if (topPointer > -1)    {
        //     for (int i=0; i <= topPointer; i++){
        //         cout << "Value " << i << ": " << arrNum[i] << endl;

        //     }

        }


    }



}