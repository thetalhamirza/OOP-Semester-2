#include <iostream>
#include <string>

using namespace std;


class Vehicle {
    protected:
        string modelName;
        double cost;
    public: 
        string getModelName() const { return modelName; }
        double getCost() const { return cost; }

        void updateModel(string m) { modelName = m; }
        virtual void updateCost(double c) = 0;  

        virtual void showDetails() = 0; 

        virtual ~Vehicle() {}
};


class PaintedVehicle : public Vehicle {
    private:
        string paintShade;
    public:
        void assignPaint(string clr) { paintShade = clr; }
        string retrievePaint() const { return paintShade; }

        void updateCost(double c) override {
            if (c < 0) {
                cout << "Invalid cost! Setting to default 0.\n";
                cost = 0;
            } else {
                cost = c;
            }
        }

        void showDetails() override {
            cout << "Vehicle Name: " << modelName << endl;
            cout << "Paint Color: " << paintShade << endl;
            cout << "Total Cost: $" << cost << endl;
            cout << "===========================" << endl;
        }
};


class BrandedVehicle : public Vehicle {
    private:
        string brandTitle;
    public:
        void assignBrand(string brand) { brandTitle = brand; }
        string retrieveBrand() const { return brandTitle; }

        void updateCost(double c) override {
            if (c < 1000) {
                cout << "Base price must be $1000 or above. Setting to $1000.\n";
                cost = 1000;
            } else {
                cost = c;
            }
        }

        void showDetails() override {
            cout << "Vehicle Name: " << modelName << endl;
            cout << "Brand: " << brandTitle << endl;
            cout << "Total Cost: $" << cost << endl;
            cout << "===========================" << endl;
        }
};

int main() {
    PaintedVehicle pv;
    BrandedVehicle bv;

    pv.updateModel("Totoya Corolla");
    pv.assignPaint("Black");
    pv.updateCost(1000);

    bv.updateModel("Civic");
    bv.assignBrand("Honda");
    bv.updateCost(23000);

    Vehicle* ptr1 = &pv;
    Vehicle* ptr2 = &bv;

    ptr1->showDetails();
    ptr2->showDetails();

    return 0;
}