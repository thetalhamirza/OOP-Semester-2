#include <iostream>
#include "Date.h"
using namespace std;



int main() {
    Date today;
    today.month = 2;
    today.day = 7;
    today.year = 2025;
    cout << "Today's date: " << endl;
    today.displayDate();
}