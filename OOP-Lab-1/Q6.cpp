#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>
using namespace std;

int main()  {

    string text, name;
    string list[7];
    float marks[5];
    int length, count = 0;
    float sum=0;
    string current = "";
    
    cout << "Enter full name with scores: ";
    getline(cin, text);
    text = text + ' ';
    for (int i=0; i<text.length(); i++)  {

        if (text[i] == ' ') {
            list[count] = current;
            count++;
            current = "";
        }   else    {
            current = current + text[i];
        }
    
    }

    name = list[0] + " " + list[1];

    for (int j = 0; j < 5; j++) {
        marks[j] = stof(list[j+2]);
        sum += marks[j];
    }

    float avg = sum / float(5);

    cout << "Student name: " << name << endl;
    printf("Test scores: %.2f %.2f %.2f %.2f %.2f\n", marks[0], marks[1], marks[2], marks[3], marks[4]);
    printf("Average test score: %.2f", avg);

}