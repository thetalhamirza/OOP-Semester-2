#include <iostream>
using namespace std;

class Employee
{
    string fname, lname;
    double monthSalary;

    public:
        double getSalary() {
            return monthSalary;
        }
        void setSalary(double sal) {
            monthSalary = sal;
            if (monthSalary < 0) {
                monthSalary = 0;
            }
            cout << "Monthly Salary set to: " << monthSalary << endl;
        }
        void raiseSalary(float percent) {
            monthSalary = monthSalary * percent / 100;
            cout << "Raised.\n" << endl;
        }

};