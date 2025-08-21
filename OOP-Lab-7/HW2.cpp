#include <iostream>
using namespace std;

class Shape {
    
    double area;

public:
    Shape(double a = 0) : area(a) {}

    double Area() const {
        return area;
    }

    Shape operator+(const Shape& second) {
        return (Shape(area+second.area));
    }

    void display() const {
        cout << "Area: " << area << endl;
    }
};

int main() {
    Shape shape1(25.5), shape2(40.2);
    Shape shape3 = shape1 + shape2;

    cout << "Shape 1: ";
    shape1.display();
    cout << "Shape 2: ";
    shape2.display();
    cout << "Total Area (Shape 3): ";
    shape3.display();

    return 0;
}
