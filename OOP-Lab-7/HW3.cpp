#include <iostream>
using namespace std;

class Person {
protected:
    int empID;

public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> empID;
    }

    void displayData() {
        cout << "Employee ID: " << empID << endl;
    }
};

class Admin : public Person {
protected:
    string name;
    double monthlyIncome;

public:
    void getData() {
        Person::getData();
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    double bonus() {
        return monthlyIncome * 0.05 * 12; // 5% annual bonus
    }

    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl;
    }
};

class Accounts : public Admin {
public:
    void getData() {
        Admin::getData();
    }

    void displayData() {
        Admin::displayData();
    }
};

int main() {
    Admin adminEmp;
    Accounts accountsEmp;

    cout << "Enter details for Admin Employee:\n";
    adminEmp.getData();
    cout << "\nEnter details for Accounts Employee:\n";
    accountsEmp.getData();

    cout << "\nAdmin Employee Details:\n";
    adminEmp.displayData();
    cout << "\nAccounts Employee Details:\n";
    accountsEmp.displayData();

    return 0;
}
