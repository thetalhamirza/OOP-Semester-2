#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>
using namespace std;




int main() {
    
    string ID;
    string name;
    int units;
    float bill, rate, surcharge = -1;

    cout << "Enter ID: ";
    cin >> ID;
    
    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter units consumed: ";
    cin >> units;

    cout << "Customer ID: " << ID << endl;
    cout << "Customer Name: " << name << endl;
    cout << "Units Consumed: " << units << endl;


    if (units <= 199)   {
        rate = 16.20;
        bill = units * 16.20;
    }   else if (units < 300)  {
        rate = 20.10;
        bill = units * 20.10;
    }   else if (units < 500)   {
        rate = 27.10;
        bill = units * 27.10;
    }   else if (units >= 500)  {
        rate = 35.90;
        bill = units * 35.90;

        surcharge = bill * 0.15;
    }
    float total = bill; 
    printf("Amount charges @Rs. %.2f per unit: %.2f\n", rate, bill);

    if (surcharge > 0)  {
        printf("Surcharge Amount: %.2f\n", surcharge);
        total += surcharge;
    }

    printf("Net Amount Paid by the Customer: %.2f\n", total);

}