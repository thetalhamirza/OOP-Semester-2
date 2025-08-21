#include <iostream>
#include <string>

using namespace std;

class ShapeBase {
    public:
        virtual float CalculateArea() = 0;
};


class Box : public ShapeBase {
    private:
        float length;
        float breadth;
    public:
        Box(float l, float b) : length(l), breadth(b) {
            
        }
        float CalculateArea() override {
            return length * breadth;
        }
};


class Pyramid : public ShapeBase {
    private:
        float baseLength;
        float heightValue;
    public:
        Pyramid(float bl, float h) : baseLength(bl), heightValue(h) {}
        float CalculateArea() override {
            return 0.5f * baseLength * heightValue;
        }
};

int main() {
    Box b1(14.0f, 22.0f);
    Pyramid p1(11.0f, 5.0f);

    cout << "Box Area: " << b1.CalculateArea() << endl;
    cout << "Pyramid Area: " << p1.CalculateArea() << endl;

    return 0;
}