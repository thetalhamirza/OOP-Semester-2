#include <iostream>
#include <string>

using namespace std;


class Employee {
    protected:
        string fullName;
        double basePay;
    public:
        virtual void inputDetails() {
            cout << "Enter Full Name: ";
            getline(cin, fullName);
            cout << "Enter Base Pay: ";
            cin >> basePay;
            cin.ignore();
        }

        virtual void showDetails() {
            cout << "Full Name: " << fullName << endl;
            cout << "Base Pay: $" << basePay << endl;
        }

        virtual void computeIncentive() = 0;
        virtual ~Employee() {}
};


class DepartmentStaff : virtual public Employee {
    protected:
        string division;
    public:
        void inputDetails() override {
            Employee::inputDetails();
            cout << "Enter Division: ";
            getline(cin, division);
        }

        void showDetails() override {
            Employee::showDetails();
            cout << "Division: " << division << endl;
        }

        void computeIncentive() override {
            double reward = 0.15 * basePay;
            cout << "Dept Staff Bonus: $" << reward << endl;
        }
};


class FinanceStaff : virtual public Employee {
    protected:
        string financeID;
    public:
        void inputDetails() override {
            Employee::inputDetails();
            cout << "Enter Finance ID: ";
            getline(cin, financeID);
        }

        void showDetails() override {
            Employee::showDetails();
            cout << "Finance ID: " << financeID << endl;
        }

        void computeIncentive() override {
            double reward = 0.12 * basePay;
            cout << "Finance Bonus: $" << reward << endl;
        }
};


class SeniorManager : public DepartmentStaff, public FinanceStaff {
    private:
        string roleTitle;
    public:
        void inputDetails() override {
            Employee::inputDetails();
            cout << "Enter Division: ";
            getline(cin, division);
            cout << "Enter Finance ID: ";
            getline(cin, financeID);
            cout << "Enter Role Title: ";
            getline(cin, roleTitle);
        }

        void showDetails() override {
            Employee::showDetails();
            cout << "Division: " << division << endl;
            cout << "Finance ID: " << financeID << endl;
            cout << "Role Title: " << roleTitle << endl;
        }

        void computeIncentive() override {
            double reward = 0.20 * basePay;
            cout << "Senior Manager Bonus: $" << reward << endl;
        }
};

int main() {
    Employee* staffMember = nullptr;
    int option;

    cout << "Choose Staff Type:\n";
    cout << "1. Department Staff\n2. Finance Staff\n3. Senior Manager\nChoice: ";
    cin >> option;
    cin.ignore();

    switch (option) {
        case 1:
            staffMember = new DepartmentStaff();
            break;
        case 2:
            staffMember = new FinanceStaff();
            break;
        case 3:
            staffMember = new SeniorManager();
            break;
        default:
            cout << "Invalid option selected.\n";
            return 1;
    }

    cout << "\n| Input Staff Info |\n";
    staffMember->inputDetails();

    cout << "\n| Staff Profile |\n";
    staffMember->showDetails();

    cout << "\n| Bonus Computation |\n";
    staffMember->computeIncentive();

    delete staffMember;
    return 0;
}