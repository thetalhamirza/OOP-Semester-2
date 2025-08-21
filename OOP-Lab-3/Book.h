#include <iostream>
using namespace std;


class Book
{
    string bookName, ISBN, author, publisher;

    public:
        Book(string name="", string isbn="", string auth="", string pub="") {
            this->bookName = name;
            this->ISBN = isbn;
            this->author = auth;
            this->publisher = pub;
        };
        string getBookName() {return this->bookName;}
        string getISBN() {return this->ISBN;}
        string getAuthor() {return this->author;}
        string getPublisher() {return this->publisher;}
        string getBookInfo() {
            cout << "Book name: " << getBookName() << "\nISBN: " << getISBN() << "\nAuthor: " << getAuthor() << "\nPublisher: " << getPublisher() << endl << endl;
        }
};