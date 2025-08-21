#include <iostream>
#include <string>
using namespace std;

struct Item {
    string itemName;
    string itemCategory;
    double itemPrice;
};

class JuiceShop {
private:
    int menuSize;
    string* orderQueue;
    int currentOrders;

public:
    const string shopName;
    Item* menu;
    
    JuiceShop(const string& name, const Item* items, int size) 
        : shopName(name), menuSize(size), orderQueue(nullptr), currentOrders(0) {
        menu = new Item[menuSize];
        for (int i = 0; i < menuSize; ++i) {
            menu[i] = items[i];
        }
    }

    ~JuiceShop() {
        delete[] menu;
        delete[] orderQueue;
    }

    string addOrder(const string& itemName) {
        bool available = false;
        for (int i = 0; i < menuSize; ++i) {
            if (menu[i].itemName == itemName) {
                available = true;
                break;
            }
        }
        if (!available) {
            return "Sorry, '" + itemName + "' is not available!";
        }
        
        string* newQueue = new string[currentOrders + 1];
        for (int i = 0; i < currentOrders; ++i) {
            newQueue[i] = orderQueue[i];
        }
        newQueue[currentOrders] = itemName;
        
        delete[] orderQueue;
        orderQueue = newQueue;
        currentOrders++;
        return "";
    }

    string serveOrder() {
        if (currentOrders == 0) {
            return "No pending orders to serve.";
        }
        string servedItem = orderQueue[0];
        
        if (currentOrders == 1) {
            delete[] orderQueue;
            orderQueue = nullptr;
            currentOrders = 0;
        } else {
            string* newQueue = new string[currentOrders - 1];
            for (int i = 1; i < currentOrders; ++i) {
                newQueue[i - 1] = orderQueue[i];
            }
            delete[] orderQueue;
            orderQueue = newQueue;
            currentOrders--;
        }
        return "Your " + servedItem + " is ready!";
    }

    string* getOrders(int& count) const {
        count = currentOrders;
        if (count == 0) {
            return nullptr;
        }
        string* ordersArray = new string[count];
        for (int i = 0; i < count; ++i) {
            ordersArray[i] = orderQueue[i];
        }
        return ordersArray;
    }

    double calculateBill() const {
        double total = 0.0;
        for (int i = 0; i < currentOrders; ++i) {
            for (int j = 0; j < menuSize; ++j) {
                if (orderQueue[i] == menu[j].itemName) {
                    total += menu[j].itemPrice;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() const {
        if (menuSize == 0) {
            return "";
        }
        string cheapest = menu[0].itemName;
        double minPrice = menu[0].itemPrice;
        
        for (int i = 1; i < menuSize; ++i) {
            if (menu[i].itemPrice < minPrice) {
                minPrice = menu[i].itemPrice;
                cheapest = menu[i].itemName;
            }
        }
        return cheapest;
    }
};

int main() {
    Item drinks[] = {
        {"Latte", "beverage", 5.0},
        {"Mocchiato", "beverage", 4.5},
        {"Cappucino", "beverage", 4.0},
        {"Banana Shake", "beverage", 5.0},
        {"Date Shake", "beverage", 4.5},
        {"Blood Booster", "beverage", 4.0},
    };

    JuiceShop shop("Starbucks", drinks, 6);
    cout << "\n\nWelcome to Starbucks!" << endl;
    
    cout << "\nThe cheapest drink available: " << shop.cheapestItem() << endl;

    cout << "\nPlacing Orders:" << endl;
    cout << shop.addOrder("Cappucino") << endl;
    cout << shop.addOrder("Mocha") << endl;
    cout << shop.addOrder("Latte") << endl;

    int orderCount;
    string* orders = shop.getOrders(orderCount);
    cout << "Current Orders (" << orderCount << "):" << endl;
    for (int i = 0; i < orderCount; ++i) {
        cout << " > " << orders[i] << endl;
    }
    delete[] orders;

    cout << "\nTotal Bill: $" << shop.calculateBill() << endl;
    
    cout << "\nOrder Processing:" << endl;
    cout << " > " << shop.serveOrder() << endl;
    cout << " > " << shop.serveOrder() << endl;
    cout << " > " << shop.serveOrder() << endl;
    
    return 0;
}