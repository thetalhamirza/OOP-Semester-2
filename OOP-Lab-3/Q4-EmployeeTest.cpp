#include <iostream>
#include "Employee.h"
using namespace std;



int main() {
    Employee emp1;
    Employee emp2;

    emp1.setSalary(25000);
    emp2.setSalary(37000);

    cout << "Employee 1 Yearly Salary: " << emp1.getSalary() * 12 << endl;
    cout << "Employee 2 Yearly Salary: " << emp2.getSalary() * 12 << endl;

    emp1.raiseSalary(10);
    emp2.raiseSalary(10);
    
    cout << "Employee 1 Yearly Salary: " << emp1.getSalary() * 12 << endl;
    cout << "Employee 2 Yearly Salary: " << emp2.getSalary() * 12 << endl;
}