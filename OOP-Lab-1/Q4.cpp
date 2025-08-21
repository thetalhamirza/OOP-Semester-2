#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>
using namespace std;


int main()  {

    float weightKilo, weightPound;

    cout << "Enter weight in kilograms: ";
    cin >> weightKilo;

    weightPound = weightKilo * 2.2;

    printf("\n\nWeight in kilograms: %.2f\n", weightKilo);
    printf("Weight in pounds: %.2f\n", weightPound);


}