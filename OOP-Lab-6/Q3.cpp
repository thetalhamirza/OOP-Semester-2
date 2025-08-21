#include <iostream>
#include <vector>
using namespace std;

class Employee
{
protected:
    string ID;
    string name;

public:
    Employee(string ID, string name) : ID(ID), name(name) {}
    virtual void IOrderTaker() = 0;
    virtual void IOrderPreparer() = 0;
    virtual void IBiller() = 0;
};
class Waiter : virtual public Employee
{
public:
    Waiter(string ID, string name) : Employee(ID, name) {}

    void IOrderTaker() override
    {
        cout << name << " (Waiter) is taking the order.\n";
    }
    void IOrderPreparer() override {}
    void IBiller() override {}
};

class Chef : virtual public Employee
{
public:
    Chef(string ID, string name) : Employee(ID, name) {}

    void IOrderTaker() override {}
    void IOrderPreparer() override
    {
        cout << name << " (Chef) is preparing the order.\n";
    }
    void IBiller() override {}
};

class Cashier : virtual public Employee
{
public:
    Cashier(string ID, string name) : Employee(ID, name) {}

    void IOrderTaker() override {}
    void IOrderPreparer() override {}
    void IBiller() override
    {
        cout << name << " (Cashier) is billing the order.\n";
    }
};

class Manager : public Waiter, public Cashier
{
public:
    Manager(string ID, string name) : Waiter(ID, name), Cashier(ID, name), Employee(ID, name) {}
    void IOrderTaker() override {
        cout << name << " (Manager) is taking the order.\n";
    }

    void IOrderPreparer() override {}

    void IBiller() override {
        cout << name << " (Manager) is billing the order.\n";
    }
};

class Menu
{
protected:
    string menuName;
    string items[5];
    double prices[5];
    int itemCount;

public:
    Menu(string name) : menuName(name), itemCount(0) {}

    void addItem(string itemName, double price)
    {
        if (itemCount < 5)
        {
            items[itemCount] = itemName;
            prices[itemCount] = price;
            itemCount++;
        }
        else
        {
            cout << "Menu is full! Cannot add more items.\n";
        }
    }

    virtual double calculateTotalCost() = 0;

    void displayMenu()
    {
        cout << menuName << " Menu:\n";
        for (int i = 0; i < itemCount; i++)
        {
            cout << "- " << items[i] << ": $" << prices[i] << endl;
        }
    }
};

class FoodMenu : public Menu
{
public:
    FoodMenu() : Menu("Food") {}

    double calculateTotalCost() override
    {
        double total = 0;
        for (int i = 0; i < itemCount; i++)
        {
            total += prices[i];
        }
        return total;
    }
};

class BeverageMenu : public Menu
{
public:
    BeverageMenu() : Menu("Beverage") {}

    double calculateTotalCost() override
    {
        double total = 0;
        for (int i = 0; i < itemCount; i++)
        {
            total += prices[i];
        }
        return total * 1.10; // 10% tx
    }
};

int main()
{

    vector<Employee *> workers;
    workers.push_back(new Waiter("001", "Haider"));
    workers.push_back(new Chef("002", "Qazi"));
    workers.push_back(new Manager("003", "Talha"));
    workers.push_back(new Cashier("004", "Panda"));

    for (int i = 0; i < workers.size(); i++)
    {
        workers.at(i)->IOrderTaker();
        workers.at(i)->IOrderPreparer();
        workers.at(i)->IBiller();
        cout << "\n----------\n\n";
    }
    

    return 0;
}
