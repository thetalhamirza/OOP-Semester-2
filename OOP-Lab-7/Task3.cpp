#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

public:
    BigInteger(string num) {
        isNegative = (num[0] == '-');
        for (int i = num.length() - 1; i >= (isNegative ? 1 : 0); --i) {
            digits.push_back(num[i] - '0');
        }
        removeLeadingZeros();
    }

    friend ostream& operator<<(ostream& os, const BigInteger& bi) {
        if (bi.isNegative) os << "-";
        for (int i = bi.digits.size() - 1; i >= 0; --i) {
            os << bi.digits[i];
        }
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& bi) {
        string num;
        is >> num;
        bi = BigInteger(num);
        return is;
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result = addMagnitude(*this, other);
            result.isNegative = isNegative;
            return result;
        }
        if (compareMagnitude(*this, other) >= 0) {
            BigInteger result = subtractMagnitude(*this, other);
            result.isNegative = isNegative;
            return result;
        } else {
            BigInteger result = subtractMagnitude(other, *this);
            result.isNegative = other.isNegative;
            return result;
        }
    }

    bool operator==(const BigInteger& other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }
        if (digits.size() != other.digits.size()) {
            return isNegative ? (digits.size() > other.digits.size()) : (digits.size() < other.digits.size());
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return isNegative ? (digits[i] > other.digits[i]) : (digits[i] < other.digits[i]);
            }
        }
        return false;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

private:
    static BigInteger addMagnitude(const BigInteger& a, const BigInteger& b) {
        BigInteger result("0");
        result.digits.clear();
        int carry = 0, sum;
        size_t size = max(a.digits.size(), b.digits.size());
        for (size_t i = 0; i < size || carry; ++i) {
            sum = carry;
            if (i < a.digits.size()) sum += a.digits[i];
            if (i < b.digits.size()) sum += b.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        return result;
    }

    static int compareMagnitude(const BigInteger& a, const BigInteger& b) {
        if (a.digits.size() != b.digits.size()) {
            return a.digits.size() > b.digits.size() ? 1 : -1;
        }
        for (int i = a.digits.size() - 1; i >= 0; --i) {
            if (a.digits[i] != b.digits[i]) {
                return a.digits[i] > b.digits[i] ? 1 : -1;
            }
        }
        return 0;
    }

    static BigInteger subtractMagnitude(const BigInteger& a, const BigInteger& b) {
        BigInteger result("0");
        result.digits.clear();
        int borrow = 0, diff;
        for (size_t i = 0; i < a.digits.size(); ++i) {
            diff = a.digits[i] - borrow - (i < b.digits.size() ? b.digits[i] : 0);
            borrow = (diff < 0);
            if (borrow) diff += 10;
            result.digits.push_back(diff);
        }
        result.removeLeadingZeros();
        return result;
    }
};

int main() {
    BigInteger num1("892356792364587326549875687268");
    BigInteger num2("725687904658709326534653875674");
    
    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;
    
    BigInteger sum = num1 + num2;
    cout << "Sum: " << sum << endl;
    
    return 0;
}
