#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car {
    string ID;
public:
    Car(string ID) {
        this->ID = ID;
        cout << "\nCar " << ID << " Constructed" << endl;
    }
    
    ~Car() {
        cout << "\nCar " << ID << " Destroyed" << endl;
    }

    string getID() {
        return ID;
    }

};

class Garage {
private:
    vector<Car*> cars;
public:
    void parkCar(Car* car) {
        cars.push_back(car);
    }

    void listCars() {
        cout << "\nCars in garage:\n";
        for (int i = 0; i < cars.size(); i++) {
            cout << "Car#" << i + 1 << ": " << cars[i]->getID() << endl;
        }
    }
};

int main() {
    Car car1("ABC123");
    Car car2("XYZ987");

    Garage garage;
    
    garage.parkCar(&car1);
    garage.parkCar(&car2);
    
    garage.listCars();
    delete(&car1);
    

    return 0;
}
