# include <iostream>
# include <string>

using namespace std;

class Users
{
    string name;
    int age;
    string licenceType;
    int contact;
    int id;
    static int counter;

    public:

    Users(string n, int a, string l, int c) : name(n), age(a), licenceType(l), contact(c), id(counter++){}

    Users(){}

    ~Users(){}

    void updateDetails()
    {
        cout << "Enter the updated age: " << endl;
        cin >> age;
        cin.ignore();

        cout << "Enter the updated licence type: " << endl;
        getline(cin, licenceType);

        cout << "Enter your updated contact number: " << endl;
        cin >> contact;
    };

    string getLicenceType()
    {
        return licenceType;
    }

    void display()
    {
        cout << "---------- User Details ----------"<< endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Licence Type: " << licenceType << endl;
        cout << "Contact Number: " << contact << endl;
        cout << "----------------------------------" << endl;
    }
};

class Vehicle
{
    int id;
    static int counter;
    string model;
    float rentalPerDay;
    int learner; // 0: not eligible, 1: eligible
    int intermediate; // 0: not eligible, 1: eligible
    int full; // 0: not eligible, 1: eligible
    int available; // 0: not available, 1: available

    public:

    Vehicle(string m, float r, int l, int i, int f, int a) : id(counter++), model(m), rentalPerDay(r), learner(l), intermediate(i), full(f), available(a){}

    Vehicle(){}

    ~Vehicle(){}

    void display()
    {
        cout << "-----------------------------------" << endl;
        cout << "Vehicle ID: " << id << endl;
        cout << "Vehicle Model: " << model << endl;
        cout << "Rental per Day is: " << rentalPerDay << " rupees" << endl;
        if (learner == 1)
        {
            cout << "This Vehicle can be hired by drivers with a licence type of 'learner'!" << endl;
        } 
        else
        {
            cout << "This Vehicle cannot be hired by drivers with a licence type of 'learner'!" << endl;
        }
        if (intermediate == 1)
        {
            cout << "This Vehicle can be hired by drivers with a licence type of 'intermediate'!" << endl;
        }
        else
        {
            cout << "This Vehicle cannot be hired by drivers with a licence type of 'intermediate'!" << endl;
        }
        if (full == 1)
        {
            cout << "This Vehicle can be hired by drivers with a licence type of 'full'!" << endl;
        }
        else
        {
            cout << "This Vehicle cannot be hired by drivers with a licence type of 'full'!" << endl;
        }
    }

    int getLearner()
    {
        return learner;
    }

    int getIntermediate()
    {
        return intermediate;
    }

    int getFull()
    {
        return full;
    }

    int getAvailable()
    {
        return available;
    }

    void setAvailable(int i)
    {
        available = i;
    }

    int getID()
    {
        return id;
    }

};

class RentalApplication
{
    string name;
    int max;
    static int counter;
    Vehicle *registeredVehicles;
    Vehicle *v;
    Users *u;

    public:

    RentalApplication(string name) : name(name)
    {
        cout << "Enter the maximum number of vehicles which can be registered: " << endl;
        cin >> max;
        registeredVehicles = new Vehicle[max];
        cin.ignore();
    }

    ~RentalApplication()
    {
        delete[] registeredVehicles;
    }

    void AddVehicle(Vehicle &v)
    {
        if (counter < max)
        {
            registeredVehicles[counter] = v;
            cout << "Vehicle has been added!" << endl;
            counter++;
        }
        else
        {
            cout << "The maximum capacity has been reached. Cannot register more vehicles." << endl;
        }
    }

    void rentAcar(Users &u)
    {
        int eligibleVehicles[max];
        int c = 0;
        string l = u.getLicenceType();
        if (l == "learner")
        {
            for (int i = 0; i < counter; i++)
            {
                if ((registeredVehicles[i].getLearner() == 1) && (registeredVehicles[i].getAvailable() == 1))
                {
                    eligibleVehicles[c] = i;
                    cout << "Option " << c+1 << endl;
                    cout << "-----------------------------------" << endl;
                    registeredVehicles[i].display();
                    c++;
                }
            }
        }
        else if (l == "intermediate")
        {
            for (int i = 0; i < counter; i++)
            {
                if ((registeredVehicles[i].getIntermediate() == 1) && (registeredVehicles[i].getAvailable() == 1))
                {
                    eligibleVehicles[c] = i;
                    cout << "Option " << c+1 << endl;
                    cout << "-----------------------------------" << endl;
                    registeredVehicles[i].display();
                    c++;
                }
            }
        }
        else if (l == "full")
        {
            for (int i = 0; i < counter; i++)
            {
                if ((registeredVehicles[i].getFull() == 1) && (registeredVehicles[i].getAvailable() == 1))
                {
                    eligibleVehicles[c] = i;
                    cout << "Option " << c+1 << endl;
                    cout << "-----------------------------------" << endl;
                    registeredVehicles[i].display();
                    c++;
                }
            }
        }
        else
        {
            cout << "Invalid Licence Type!" << endl;
        }

        if (c == 0)
        {
            cout << "We're Sorry, right now you're not eligible for any vehicle." << endl;
        } 
        else
        {
            int choice;
            cout << "Select a car number from " << 1 << " to " << c << endl;
            cin >> choice;
            while (choice < 1 || choice > c)
            {
                cout << "Enter a valid number: " << endl;
                cin >> choice;
            }
            registeredVehicles[eligibleVehicles[choice-1]].setAvailable(0); // Set to unavailable
            cout << "You have rented the Car!" << endl;
        }


    }

    void removeVehicle()
    {
        if (counter > 0)
        {
            int ID;
            cout << "Enter the ID of the vehicle you want to remove: " << endl;
            cin >> ID;
            
            int found = 0;
            int i = 0;
            while ((found == 0) && (i < counter))
            {
                if (registeredVehicles[i].getID() == ID)
                {
                    found = 1;
                    break;
                }
                i++;
            }
            if (found == 1)
            {
                for (int j = i; j < counter-1; j++)
                {
                    registeredVehicles[j] = registeredVehicles[j+1];
                }
                counter--;
                cout << "Vehicle Removed!" << endl;
            }
            else
            {
                cout << "Invalid Vehicle ID." << endl;
            }
        }
        else
        {
            cout << "No Vehicles Registered." << endl;
        }
    }

    void printDetails()
    {
        cout << "-------- Cars Available & their details ----------------" << endl;
        for (int i = 0; i < counter; i++)
        {
            registeredVehicles[i].display();
        }
        cout << "-------------------------------------------------" << endl;
    }
        

};

int Users :: counter = 0;
int Vehicle :: counter = 0;
int RentalApplication :: counter = 0;


int main()
{
    
	cout << "Name: Talha Mirza" << endl;
	cout << "24K-0973\n" << endl;

    cout << "\n*****Rental A Car Application*****" << endl;
    RentalApplication app("MyRentalApp");

    Vehicle v1("Toyota Corolla", 1000.0, 1, 1, 1, 1);
    Vehicle v2("Honda Civic", 1200.0, 0, 1, 1, 1);
    Vehicle v3("Suzuki Alto", 800.0, 1, 0, 0, 1);

    app.AddVehicle(v1);
    app.AddVehicle(v2);
    app.AddVehicle(v3);

    cout << "\n----- All Available Vehicles -----" << endl;
    app.printDetails();

    Users user1("Talha", 25, "full", 1234567890);

    cout << "\n----- Rent A Car -----" << endl;
    cout << "\n----- Vehicles Eligible for you -----" << endl;
  
    app.rentAcar(user1);

    cout << "\n----- Remove Vehicle -----" << endl;
    
    app.removeVehicle();

    cout << "\n----- Update User Details -----" << endl;
    user1.updateDetails();
    user1.display();
    
    cout << "\n----- Program Ended -----" << endl;
    return 0;
}