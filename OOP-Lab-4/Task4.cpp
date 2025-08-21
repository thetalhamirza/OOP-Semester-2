#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Books
{    
    public:
    string bookTitle;
    string author;
    string publisher;
    int quantity;
    double pricePerItem;

    Books(string bookTitle, string author, string publisher, int quantity, double pricePerItem)
    {
        this->bookTitle=bookTitle;
        this->author=author;
        this->publisher=publisher;
        this->quantity=quantity;
        this->pricePerItem=pricePerItem;
    }

    void getBook(string bookTitle, string author)
    {
        cout << "Book Title: " << bookTitle << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per Item: " << pricePerItem << endl;
    }
    
};


int main()  {
    int flag = 0, index;
    string sbookTitle, sauthor;
    Books bookList[3]={Books("The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", 10, 75), Books("The Catcher in the Rye", "J.D. Salinger", "Little, Brown and Company", 0, 65), Books("To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", 5, 50)};
    getline(cin, sbookTitle);
    getline(cin, sauthor);
    
    for (int i = 0; i < 3; i++)
    {
        if (bookList[i].bookTitle == sbookTitle && bookList[i].author == sauthor)
        {
            flag = 1;
            index = i;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "Book found!" << endl;
        bookList[index].getBook(sbookTitle, sauthor);
        cout << "Number of copies required: " << endl;
        int n;
        cin >> n;
        if (n <= bookList[index].quantity)
        {
            cout << "Total cost: " << n*bookList[index].pricePerItem << endl;
        }
        else
        {
            cout << "Required copies not in stock" << endl;
        }
    }
    else
    {
        cout << "Book not found!" << endl;
    }


}