#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class MenuItem
{
    public:
    string name;
    string type;
    double price;
};


class CoffeeShop
{

    public:
    string name;
    MenuItem items[7];
    string orders[10];
    int pointer = 0;
    double revenue = 0;

    string addOrder(string item)    {
        int flag=0;
        for (int i = 0; i < 7; i++) 
        {
            if (items[i].name == item)
            {
                orders[pointer] = item;
                pointer++;
                revenue += items[i].price;
                flag = 1;
                break; 
            }
        }
        if (flag == 1)
        {
            return "Order added!";
        } else {
            return "This item is currently unavailable!";
        }
    }

    string fulfillOrder()   {
        if (pointer == 0)
        {
            return "All orders have been fulfilled!";
        } else {
            string order = orders[0];
            for (int i = 0; i < pointer - 1; i++) 
            {
                orders[i] = orders[i+1];
            }
            pointer--; 
            return "The " + order + " is ready!";
        }
    }

    string* listOrders() {
        return orders;
    } 

    double dueAmount()  {
        return revenue;
    }

    string cheapestItem()   {
        double min = items[0].price;
        string name = items[0].name;
        for (int i = 1; i < 7; i++) 
        {
            if (items[i].price < min && items[i].name != "")
            {
                min = items[i].price;
                name = items[i].name;
            }
        }
        return name;
    }

    string drinksOnly() {
        string drinks = "";
        for (int i = 0; i < 7; i++)
        {
            if (items[i].type == "drink")
            {
                drinks += items[i].name + ", ";
            }
        }
        return drinks;
    }

    string foodOnly() {
        string food = "";
        for (int i = 0; i < 7; i++)
        {
            if (items[i].type == "food")
            {
                food += items[i].name + ", ";
            }
        }
        return food;
    }


};


int main()  {

    CoffeeShop starbucks;
    starbucks.name = "Starbucks";
    starbucks.items[0].name = "Latte";
    starbucks.items[0].type = "drink";
    starbucks.items[0].price = 3.50;
    starbucks.items[1].name = "Cappuccino";
    starbucks.items[1].type = "drink";
    starbucks.items[1].price = 3.00;
    starbucks.items[2].name = "Mocha";
    starbucks.items[2].type = "drink";
    starbucks.items[2].price = 3.75;
    starbucks.items[3].name = "Burger";
    starbucks.items[3].type = "food";
    starbucks.items[3].price = 5.00;
    starbucks.items[4].name = "Sandwich";
    starbucks.items[4].type = "food";
    starbucks.items[4].price = 4.50;

    cout << starbucks.addOrder("Latte") << endl;
    cout << starbucks.addOrder("Burger") << endl;
    cout << starbucks.addOrder("Mocha") << endl;
    cout << starbucks.addOrder("Cappuccino") << endl;
    cout << starbucks.addOrder("Sandwich") << endl;

    cout << starbucks.fulfillOrder() << endl;
    cout << starbucks.fulfillOrder() << endl;
    cout << starbucks.fulfillOrder() << endl;
    cout << starbucks.fulfillOrder() << endl;
    cout << starbucks.fulfillOrder() << endl;
    cout << starbucks.fulfillOrder() << endl;
    cout << starbucks.fulfillOrder() << endl;

    cout << starbucks.dueAmount() << endl;
    cout << starbucks.cheapestItem() << endl;
    cout << starbucks.drinksOnly() << endl;
    cout << starbucks.foodOnly() << endl;

    return 0;
}
















