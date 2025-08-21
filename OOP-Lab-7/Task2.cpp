#include <iostream>
#include <vector>
#include <algorithm>

class Polynomial;

class PolynomialUtils {
    public:
        static int evaluate(const Polynomial& p, int x);
        static Polynomial derivative(const Polynomial& p);
    };
    
    class Polynomial {
    private:
        std::vector<int> coefficients; 
        void trim() {
            while (!coefficients.empty() && coefficients.back() == 0) {
                coefficients.pop_back();
            }
        }
    
    public:

    Polynomial() {}
    Polynomial(const std::vector<int>& coeffs) : coefficients(coeffs) { trim(); }

    Polynomial operator+(const Polynomial& second) const {
        std::vector<int> result(std::max(coefficients.size(), second.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); ++i) result[i] += coefficients[i];
        for (size_t i = 0; i < second.coefficients.size(); ++i) result[i] += second.coefficients[i];
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& second) const {
        std::vector<int> result(std::max(coefficients.size(), second.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); ++i) result[i] += coefficients[i];
        for (size_t i = 0; i < second.coefficients.size(); ++i) result[i] -= second.coefficients[i];
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& second) const {
        std::vector<int> result(coefficients.size() + second.coefficients.size() - 1, 0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < second.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * second.coefficients[j];
            }
        }
        return Polynomial(result);
    }

    friend class PolynomialUtils;

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
        if (p.coefficients.empty()) {
            os << "0";
            return os;
        }
        bool first = true;
        for (int i = p.coefficients.size() - 1; i >= 0; --i) {
            if (p.coefficients[i] != 0) {
                if (!first) os << (p.coefficients[i] > 0 ? " + " : " - ");
                else if (p.coefficients[i] < 0) os << "-";
                if (std::abs(p.coefficients[i]) != 1 || i == 0) os << std::abs(p.coefficients[i]);
                if (i > 0) os << "x";
                if (i > 1) os << "^" << i;
                first = false;
            }
        }
        return os;
    }
};

int PolynomialUtils::evaluate(const Polynomial& p, int x) {
    int result = 0;
    int power = 1;
    for (int coeff : p.coefficients) {
        result += coeff * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial& p) {
    if (p.coefficients.size() <= 1) return Polynomial(); 
    std::vector<int> deriv_coeffs(p.coefficients.size() - 1);
    for (size_t i = 1; i < p.coefficients.size(); ++i) {
        deriv_coeffs[i - 1] = p.coefficients[i] * i;
    }
    return Polynomial(deriv_coeffs);
}

int main() {
    Polynomial p1({2, -3, 5});
    Polynomial p2({1, 2, 1}); 

    std::cout << "p1: " << p1 << "\n";
    std::cout << "p2: " << p2 << "\n";
    std::cout << "p1 + p2: " << (p1 + p2) << "\n";
    std::cout << "p1 - p2: " << (p1 - p2) << "\n";
    std::cout << "p1 * p2: " << (p1 * p2) << "\n";
    std::cout << "p1 evaluated at x=2: " << PolynomialUtils::evaluate(p1, 2) << "\n";
    std::cout << "Derivative of p1: " << PolynomialUtils::derivative(p1) << "\n";
    return 0;
}
