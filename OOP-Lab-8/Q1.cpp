#include <iostream>
using namespace std;

class Account {
    string accNumber, accHolderName, accType;
    string* transHistory;
    int historyTopPointer = 0;
    protected:
    float bal;
    public:
    Account(string accNum, string holder, float balAdd, string type="General") : bal(0), accNumber(accNum), accHolderName(holder), accType(type) {
        transHistory = new string[10];
        deposit(balAdd);
    }

    virtual void deposit(float amt) {
        bal += amt;
        cout << "Deposited: " << amt << endl;
        cout << "New Balance: " << bal << endl;
        transHistory[historyTopPointer++] = "Deposited: " + to_string(amt);
    }
    virtual void withdraw(float amt) {
        if (bal > 0) {
            if (amt > bal) {
                cout << "Insufficient Balance" << endl;
            } else {
                bal -= amt;
                cout << "Withdrawn: " << amt << endl;
                cout << "New Balance: " << bal << endl;
                transHistory[historyTopPointer++] = "Withdrawn: " + to_string(amt);
            }
        }   else {
            cout << "Zero Balance" << endl;
        }
    }
    virtual void calculateInterest() {
        cout << "Interest: " << 0.03 * bal << endl;
    }
    void getAccountInfo() {
        cout << "\nAccount Number: " << accNumber << endl;
        cout << "Account Holder: " << accHolderName << endl;
        cout << "Account Type: " << accType << endl;
        cout << "Current Balance: " << bal << endl << endl;
    }
    void printStatement() {
        for (int i=0; i<10; i++) {
            cout << transHistory[i] << endl;
        }
    }

    float getBalance() {return bal;}

    virtual ~Account() {}

};


class SavingsAccount : public Account {
    float interestRate, minBalance;
    public:
    SavingsAccount(string accNum, string holder, float balAdd, float rate, float minBal) : Account(accNum, holder, balAdd, "Savings"), interestRate(rate), minBalance(minBal) {
        if (balAdd < minBal) {cout << "The added balance is less than the minimum balance for account creation\nPlease consider adding more balance...";}
    }
    void calculateInterest() override {
        double interest = bal * (interestRate / 100);
        cout << "Interest earned: $" << interest << endl;
        bal += interest;
    }
    void withdraw(float amount) override {
        if (bal - amount < minBalance) {
            cout << "Withdrawal denied! Maintaining minimum balance of " << minBalance << " is required." << endl;
        } else {
            Account::withdraw(amount);
        }
    }

};

class CheckingAccount : public Account {
    public:
    CheckingAccount(string accNum, string holder, double bal)
        : Account(accNum, holder, bal, "Checking") {}
};

class FixedDepositAccount : public Account {
    private:
    string maturityDate;
    double fixedInterestRate;

    public:
    FixedDepositAccount(string accNum, string holder, double bal, string maturity, double rate)
        : Account(accNum, holder, bal, "Fixed Deposit"), maturityDate(maturity), fixedInterestRate(rate) {}

    void calculateInterest() override {
        cout << "Fixed interest of " << fixedInterestRate << "% applied until maturity date: " << maturityDate << endl;
    }

    void withdraw(float amount) override {
        cout << "Withdrawals are not allowed before maturity date: " << maturityDate << endl;
    }


};

int main() {
    vector<Account*> accounts;

    accounts.push_back(new SavingsAccount("SA123", "Alice", 2000.0, 5.0, 500.0));
    accounts.push_back(new CheckingAccount("CA456", "Bob", 1500.0));
    accounts.push_back(new FixedDepositAccount("FD789", "Charlie", 5000.0, "01-01-2026", 6.5));

    for (auto acc : accounts) {
        acc->printStatement();
        cout << "---------------------\n";
        acc->calculateInterest();
        acc->withdraw(600);
        cout << "=====================\n";
    }

    for (auto acc : accounts) {
        delete acc;
    }

    return 0;
}
