#include <iostream>
using namespace std;

class Currency {
    protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate; 

    public:
    Currency(double amt, string code, string symbol, double rate)   : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() const {
        return amount * exchangeRate;
    }

    virtual double convertTo(const Currency &targetCurrency) const {
        double baseAmount = convertToBase();
        return baseAmount / targetCurrency.exchangeRate;
    }

    virtual void displayCurrency() const {
        cout << "Amount: " << currencySymbol << amount
             << " (" << currencyCode << ")\n";
    }

    virtual ~Currency() {}
};

class Dollar : public Currency {
    public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() const override {
        cout << "USD: $" << amount << endl;
    }
};

class Euro : public Currency {
    public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.08) {} 

    void displayCurrency() const override {
        cout << "EUR: €" << amount << endl;
    }
};

class Rupee : public Currency {
    public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs.", 0.012) {} 

    void displayCurrency() const override {
        cout << "PKR: Rs." << amount << endl;
    }
};

int main() {
    Dollar usd(100);
    Euro eur(100);
    Rupee pkr(1000);

    usd.displayCurrency();
    eur.displayCurrency();
    pkr.displayCurrency();

    cout << "\nConversions:\n";
    cout << "100 USD to EUR: " << usd.convertTo(eur) << " EUR" << endl;
    cout << "100 EUR to PKR: " << eur.convertTo(pkr) << " PKR" << endl;
    cout << "1000 PKR to USD: " << pkr.convertTo(usd) << " USD" << endl;

    return 0;
}
