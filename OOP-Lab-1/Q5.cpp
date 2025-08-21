#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>
using namespace std;

int main()  {

    string mname;
    float adultPrice, childPrice, percentage;
    int adultSold, childSold;

    cout << "\nEnter Movie Name: ";
    getline(cin, mname);
    cout << "\nEnter adult ticket price: ";
    cin >> adultPrice;
    cout << "\nEnter child ticket price: ";
    cin >> childPrice;
    cout << "\nEnter adult tickets sold: ";
    cin >> adultSold;
    cout << "\nEnter child tickets sold: ";
    cin >> childSold;
    cout << "\nEnter percentage to be donated: ";
    cin >> percentage;

    int totalSold = adultSold + childSold;
    float amount = (adultPrice * adultSold) + (childPrice * childSold);
    float donation = amount * percentage / 100;
    float net = amount - donation;

    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "Movie Name: .................................... " << mname << endl;
    cout << "Number of Tickets Sold: .......................... " << totalSold << endl;
    printf("Gross Amount: ......................................... $ %.2f", amount);
    printf("\nPercentage of Gross Amount Donated: %.2f", percentage);
    printf("\nAmount Donated: ................................... $ %.2f", donation);
    printf("\nNet Sale: ................................................... $ %.2f", net);


}