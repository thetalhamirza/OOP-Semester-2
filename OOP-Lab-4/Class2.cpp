#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Polynomial
{
    public:
    double *coeff;
    int degree;

    Polynomial()
    {
        degree = 0;
        coeff = new double[1];
    }

    Polynomial(int deg)
    {
        degree = deg;
        coeff = new double[deg+1];
    }

    Polynomial (const Polynomial &copy)
    {
        degree = copy.degree;
        coeff = new double[degree+1];
        for(int i=0; i<=degree; i++)
        {
            coeff[i] = copy.coeff[i];
        }
    }

    Polynomial(Polynomial &&move) noexcept
    {
        degree = move.degree;
        coeff = move.coeff;
        move.degree = 0;
        move.coeff = nullptr;
    }

    ~Polynomial()
    {
        delete[] coeff;
    }
    
    
    int getDegree() const { return degree; }
    double evaluate(double x) const {
        double result = 0;
        for(int i=0; i<=degree; i++)    {
            result += coeff[i] * pow(x, i);
        }
        return result;
    }

    Polynomial add(const Polynomial &p) const {
        int newDegree = max(degree, p.degree);
        Polynomial result(newDegree);
        for(int i=0; i<=newDegree; i++) {
            if(i<=degree && i<=p.degree) {
                result.coeff[i] = coeff[i] + p.coeff[i];
            } else if(i<=degree) {
                result.coeff[i] = coeff[i];
            } else {
                result.coeff[i] = p.coeff[i];
            }
        }
        return result;
    }

    Polynomial multiply(const Polynomial &p) const {
        int newDegree = degree + p.degree;
        Polynomial result(newDegree);
        for(int i=0; i<=degree; i++) {
            for(int j=0; j<=p.degree; j++) {
                result.coeff[i+j] += coeff[i] * p.coeff[j];
            }
        }
        return result;
    }


};


int main()  {
    Polynomial p1(2);
    p1.coeff[0] = 1;
    p1.coeff[1] = 2;
    p1.coeff[2] = 3;

    Polynomial p2(1);
    p2.coeff[0] = 4;
    p2.coeff[1] = 5;

    Polynomial p3 = p1.add(p2);
    Polynomial p4 = p1.multiply(p2);

    cout << "p1: " << p1.evaluate(2) << endl;
    cout << "p2: " << p2.evaluate(2) << endl;
    cout << "p3: " << p3.evaluate(2) << endl;
    cout << "p4: " << p4.evaluate(2) << endl;

    return 0;
}