#include <iostream>
using namespace std;

class Glass
{

    public:
        int LiquidLevel = 200;


        void Drink(int milliliters) {
            LiquidLevel -= milliliters;
            cout << "Drank " << milliliters << "ml\n" << endl;
            cout << "Liquid level is now " << LiquidLevel  << "ml\n" << endl;
            if (LiquidLevel < 100) {
                cout << "Liquid level low!\n" << endl;
                Refill();
            }
        }

        void Refill() {
            LiquidLevel = 200;
            cout << "Refilled to 200ml\n" << endl;
        }


};


int main() {
    Glass wine1;
    int drank, choice = 5;
    while (choice != 0) {
        cout << "Choose an option\n" << endl;
        cout << "1. Drink" << endl;
        cout << "2. Refill" << endl;
        cout << "3. Display Level" << endl;
        cout << "0. Exit\n\n" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "How much? --> ";
            cin >> drank;
            wine1.Drink(drank);
        } else if (choice == 2)    {
            wine1.Refill();
        } else if (choice == 3)    {
            cout << wine1.LiquidLevel << "ml" << endl;
        }   else if (choice == 0) {
            break;   
        }   else {
            cout << "Invalid choice\n" << endl;
        }
    
    }
}
