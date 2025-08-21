#include <iostream>
using namespace std;

class Number {

    int value;

public:
    Number(int v) : value(v) {}

    void display() const {
        cout << "Value: " << value << endl;
    }

    Number& operator--() {
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }
};

int main() {
    Number num(16);
    cout << "Initial value: ";
    num.display();

    --num;
    cout << "Prefix: ";
    num.display();

    num--;
    num--;
    cout << "Postfix: ";
    num.display();

    return 0;
}