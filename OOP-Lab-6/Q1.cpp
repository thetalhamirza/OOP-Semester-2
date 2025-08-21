#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accountNumber, double balance = 0.0)
        : accountNumber(accountNumber), balance(balance) {}

    virtual void setBalance(double balance) { this->balance = balance; }
    void setAccountNumber(string accountNumber) { this->accountNumber = accountNumber; }

    virtual double getBalance() { return balance; }
    string getAccountNumber() { return accountNumber; }

    virtual void display() {
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: $" << balance << "\n";
    }

    virtual void deposit(double amount) {
        balance += amount;
        cout << "$" << amount << " deposited successfully!\n";
        cout << "Remaining Balance: $" << balance << "\n";
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "$" << amount << " withdrawn successfully!\n";
            cout << "Remaining Balance: $" << balance << "\n";
        } else {
            cout << "Cannot withdraw, insufficient funds\n";
        }
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string accountNumber, double balance)
        : BankAccount(accountNumber, balance) {}

    void applyRoyalty(double rate) { balance += balance * rate; }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;

public:
    CheckingAccount(string accountNumber, double balance, double overdraftLimit)
        : BankAccount(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    void withdraw(double amount) override {
        if ((balance + overdraftLimit) >= amount) {
            balance -= amount;
            cout << "$" << amount << " withdrawn successfully!\n";
        } else {
            cout << "Warning! $" << amount << " exceeds overdraft limit: $" << overdraftLimit << "\n";
        }
    }
};

class BusinessAccount : public BankAccount {
    int taxRate;

public:
    BusinessAccount(string accountNumber, double balance, int taxRate)
        : BankAccount(accountNumber, balance), taxRate(taxRate) {}

    void deposit(double amount) override {
        double taxedAmount = amount * taxRate;
        balance += taxedAmount;
        cout << "$" << taxedAmount << " deposited successfully!\n";
        cout << "Remaining Balance: $" << balance << "\n";
    }
};

class User : public BankAccount {
public:
    User(string accountNumber) : BankAccount(accountNumber) {}
};

class Customer : public User {
public:
    Customer(string accountNumber) : User(accountNumber) {}

    void display(BankAccount *bank) {
        bank->display();
        cout << "Customer can deposit & withdraw from their own account\n";
    }
};

class Employee : public User {
public:
    Employee(string accountNumber) : User(accountNumber) {}
};

class Teller : public Employee {
public:
    Teller(string accountNumber) : Employee(accountNumber) {}

    void display(BankAccount *bank) {
        bank->display();
        cout << "Teller can deposit, withdraw & freeze accounts\n";
    }
};

class Manager : public Employee {
public:
    Manager(string accountNumber) : Employee(accountNumber) {}

    void display(BankAccount *bank) {
        bank->display();
        cout << "Manager can deposit, withdraw, freeze accounts & adjust account limits\n";
    }
};

int main() {
    vector<BankAccount *> accounts;

    
    accounts.push_back(new SavingsAccount("0001", 99.99)),
    accounts.push_back(new CheckingAccount("0002", 199.99, 29.99)),
    accounts.push_back(new BusinessAccount("0003", 299.99, 5));

    for (BankAccount *account : accounts) {
        account->display();
    }

    vector<User *> users;

    users.push_back(new Customer("0001"));
    users.push_back(new Teller("0002"));
    users.push_back(new Manager("0003"));

    for (size_t i = 0; i < users.size(); ++i) {
        users[i]->deposit((i + 1) * 100);
        users[i]->display();
    }

    return 0;
}
