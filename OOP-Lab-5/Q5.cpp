#include <iostream>
using namespace std;

class Vehicle {
public:
    mutable int HorsePower;
    mutable int SeatCount;
    mutable int SpeakerCount;
    
    void ModifyAttributes(int power, int seats, int speakers) const {
        HorsePower = power;
        SeatCount = seats;
        SpeakerCount = speakers;
    }
    
    void ShowDetails() const {
        cout << "Horsepower: " << HorsePower << endl
             << "Seat Count: " << SeatCount << endl
             << "Speakers Installed: " << SpeakerCount << endl << endl;
    }
};

int main() {
    Vehicle Specs;
    Specs.HorsePower = 150;
    Specs.SeatCount = 4;
    Specs.SpeakerCount = 6;

    cout << "\nDefault Specifications:" << endl;
    Specs.ShowDetails();

    Specs.ModifyAttributes(250, 6, 8);
    cout << "\nUpdated Specifications via Constant Function:" << endl;
    Specs.ShowDetails();
    
    return 0;
}
