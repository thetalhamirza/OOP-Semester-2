#include <iostream>
using namespace std;

class Shape {
    protected:
    string position;
    string color;
    double borderThickness;

    public:
    Shape(string pos, string col, double border = 1.0) : position(pos), color(col), borderThickness(border) {}

    virtual void draw() const {
        cout << "Drawing a shape at " << position << " with color " << color << " and border thickness " << borderThickness << endl;
    }

    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
    private:
    double radius;

    public: 
    Circle(string pos, string col, double rad, double border = 1.0)
        : Shape(pos, col, border), radius(rad) {}

    void draw() const override {
        cout << "Drawing a Circle at " << position << " with color " << color << ", radius " << radius << ", and border thickness " << borderThickness << endl;
    }

    double calculateArea() const override {
        return 3.142 * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * 3.142 * radius;
    }
};

class Rectangle : public Shape {
    private:
    double width, height;

    public:
    Rectangle(string pos, string col, double w, double h, double border = 1.0) : Shape(pos, col, border), width(w), height(h) {}

    void draw() const override {
        cout << "Drawing a Rectangle at " << position << " with color " << color << ", width " << width << ", height " << height << ", and border thickness " << borderThickness << endl;
    }

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }
};
    
class Triangle : public Shape {
    private:
    double side1, side2, side3;

    public:
    Triangle(string pos, string col, double s1, double s2, double s3, double border = 1.0)  : Shape(pos, col, border), side1(s1), side2(s2), side3(s3) {}

    void draw() const override {
        cout << "Drawing a Triangle at " << position << " with color " << color << ", sides (" << side1 << ", " << side2 << ", " << side3 << "), and border thickness " << borderThickness << endl;
    }

    double calculateArea() const override {
        double s = (side1 + side2 + side3) / 2; 
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));  // Hero's formula
    }

    double calculatePerimeter() const override {
        return side1 + side2 + side3;
    }
};

int main() {
    Shape* shapes[] = {
        new Circle("Center(0,0)", "Red", 5.0),
        new Rectangle("Top-Left(2,2)", "Blue", 4.0, 6.0),
        new Triangle("Vertex(1,1)", "Green", 3.0, 4.0, 5.0)
    };

    for (Shape* shape : shapes) {
        shape->draw();
        cout << "Area: " << shape->calculateArea() << endl;
        cout << "Perimeter: " << shape->calculatePerimeter() << endl;
        cout << "---------------------\n";
    }

    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
