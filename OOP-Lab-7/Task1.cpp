#include <iostream>
#include <numeric>
using namespace std;

class Fraction {

    int numerator, denominator;

    int gcdVal(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    

    void reduce() {
        int gcd = gcdVal(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    public:
    Fraction(int n, int d)  {
        this->numerator = n;
        this->denominator = d;
        reduce();
    }

    Fraction operator+(const Fraction& second) const {
        return Fraction(numerator * second.denominator + denominator * second.numerator, denominator * second.denominator);
    }

    Fraction operator-(const Fraction& second) const {
        return Fraction(numerator * second.denominator - second.numerator * denominator, denominator * second.denominator);
    }

    Fraction operator*(const Fraction& second) const {
        return Fraction(numerator * second.numerator, denominator * second.denominator);
    }

    Fraction operator/(const Fraction& second) const {
        if (second.numerator == 0) {
            cout << "Division by 0" << endl;
        }
        return Fraction(numerator * second.denominator, denominator * second.numerator);
    }

    bool operator==(const Fraction& second) const {
        return numerator == second.numerator && denominator == second.denominator;
    }

    bool operator!=(const Fraction& second) const {
        return !(*this == second);
    }

    bool operator<(const Fraction& second) const {
        return numerator * second.denominator < second.numerator * denominator;
    }

    bool operator>(const Fraction& second) const {
        return second < *this;
    }

    bool operator<=(const Fraction& second) const {
        return !(second < *this);
    }

    bool operator>=(const Fraction& second) const {
        return !(*this < second);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator;
        if (f.denominator != 1) {
            os << "/" << f.denominator;
        }
        return os;
    }
    
    friend istream& operator>>(istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        if (f.denominator == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        f.reduce();
        return is;
    }

};

int main() {
    Fraction f1(2, 4), f2(3, 6);
    std::cout << (f1 + f2) << std::endl; // Should output 1
    return 0;
}
