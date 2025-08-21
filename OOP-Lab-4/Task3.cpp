#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Invoice
{    
    public:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

    Invoice(string partNumber, string partDescription, int quantity, double pricePerItem)
    {
        this->partNumber=partNumber;
        this->partDescription=partDescription;
        this->quantity=quantity;
        this->pricePerItem=pricePerItem;
    }

    double getInvoiceAmount()
    {
        if(quantity<0)
        {
            quantity=0;
        }
        if(pricePerItem<0)
        {
            pricePerItem=0;
        }
        return quantity*pricePerItem;
    }
};

int main()  {
    Invoice invoice1("0012", "SSD 256GB", 10, 75);
    Invoice invoice2("0013", "RAM 16GB", 0, 65);
    cout<<"Invoice 1: "<<invoice1.partNumber<<" "<<invoice1.partDescription<<" "<<invoice1.quantity<<" "<<invoice1.pricePerItem<<" "<<invoice1.getInvoiceAmount()<<endl;
    cout<<"Invoice 2: "<<invoice2.partNumber<<" "<<invoice2.partDescription<<" "<<invoice2.quantity<<" "<<invoice2.pricePerItem<<" "<<invoice2.getInvoiceAmount()<<endl;
    return 0;
}