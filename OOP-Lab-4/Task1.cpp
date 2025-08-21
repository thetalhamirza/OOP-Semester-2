#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Circle
{
    float radius;

    public:

    Circle(float rad)    {
        this->radius = rad;
    }


    float getArea() {
        return 3.142*radius*radius;
    }

    float getPerimeter()    {
        return 2*3.142*radius;
    }



};

int main(int argc, char *argv[])  {

    Circle ball(stoi(argv[1]));

    printf("\nArea = %.2f\n",ball.getArea());
    printf("\nPerimeter = %.2f\n",ball.getPerimeter());


}