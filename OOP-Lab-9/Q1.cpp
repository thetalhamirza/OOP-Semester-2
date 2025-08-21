#include <iostream>
using namespace std;

class User;

class Wallet {
    private:
    double balance;
    double depositLimit;                // assuming this is a single-day simulation and no date reset needed
    double withdrawLimit;
    string walletID;

    public:
    Wallet(string wID, double b=0, double dL=25000, double wL=25000) : balance(b), depositLimit(dL), withdrawLimit(wL), walletID(wID) {cout << "Wallet created: " << walletID << endl;}

    void deposit(double amt) {
        if (amt > depositLimit) {
            cout << "Amount greater than your deposit limit" << endl;
        }   else    {
            balance += amt;
            depositLimit -= amt;
            cout << "Amount deposited: " << amt << endl;
            cout << "New Balance: " << balance << endl;
        }
    }
    void withdraw(double amt) {
        if (amt > withdrawLimit) {
            cout << "Amount greater than your withdraw limit" << endl;
        }   else {
            if (amt > balance) {
                cout << "Insufficient Balance" << endl;
            }   else    {
                balance -= amt;
                cout << "Amount withdrawn: " << amt << endl;
                cout << "New Balance: " << balance << endl;
            }
        }
    }
    void checkBalance() {cout << "Your balance is: " << balance << endl;}

};

class User {
    string userID;
    string name;
    Wallet* wallet;

    public:
    User(string uID, string n) : userID(uID), name(n) {
        wallet = new Wallet(userID);
    }

    ~User() {
        delete wallet;
    }
    
    void deposit(double amt) {wallet->deposit(amt);}
    void withdraw(double amt)   {wallet->withdraw(amt);}
    void checkBalance() {wallet->checkBalance();}

};

int main() {
    User Talha("ABA123", "Talha");
    User Izaan("ROI214", "Izaan");
    Talha.checkBalance();
    Talha.deposit(100000);
    Talha.deposit(25000);
    Talha.checkBalance();

    Izaan.withdraw(10);
    Izaan.checkBalance();
    Izaan.deposit(20);
    Izaan.withdraw(10);
}