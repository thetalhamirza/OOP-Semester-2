#include <iostream>
#include <string>
using namespace std;

class Learner {
private:
    const int RegNumber;
    string FullName;
public:
    Learner(int regID, string lName) : RegNumber(regID), FullName(lName) {}
    void ShowDetails() const {
        cout << "\nFull Name: " << FullName << endl;
        cout << "Registration Number: " << RegNumber << endl;
    }
};

int main() {
    int regID;
    string lName;
    
    cout << "\nEnter Full Name: ";
    getline(cin, lName);
    cout << "\nEnter Registration ID: ";
    cin >> regID;
    
    Learner StudentProfile(regID, lName);
    
    cout << "\n\nProfile Summary:" << endl;
    StudentProfile.ShowDetails();
    
    return 0;
}
