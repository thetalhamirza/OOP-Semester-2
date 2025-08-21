#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Account
{
    int acc_no;
    string name;
    float balance;

    public:

    Account(int acc_no, string name, float balance)    {
        this->acc_no = acc_no;
        this->name = name;
        this->balance = balance;
    }

    void credit(float amount)  {
        balance += amount;
        cout << "\nAmount credited: " << amount << endl;
    }    

    void debit(float amount) {
        if(balance < amount)    {
            cout << "\nInsufficient balance\n" << endl;
            return;
        }
        balance -= amount;
        cout << "\nAmount debited: " << amount << endl;
    }

    void getBalance()  {
        cout << "\nBalance: " << balance << endl;
    }

};


int main()  {
    
    Account a(1234, "John Doe", 1000);

    a.credit(500);
    a.getBalance();

    a.debit(2000);
    a.getBalance();

    a.debit(500);
    a.getBalance();
}