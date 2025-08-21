#include <iostream>
#include <string>

using namespace std;

class Book {
    string title;
    string ISBN;
public:
    Book(string t, string i) : title(t), ISBN(i) {
        cout << "\nBook Created: " << title << " (" << ISBN << ")" << endl;
    }

    ~Book() {
        cout << "\nBook Destroyed: " << title << " (" << ISBN << ")\n" << endl;
    }

    string getISBN(){
         return ISBN; 
        }
    string getTitle(){
         return title;
        }
};

class Catalog {
    Book* books[100];
    string isbns[100];
    int count;
public:
    Catalog() : count(0) {}

    void addBook(Book* book) {
        books[count] = book;
        isbns[count] = book->getISBN();
        count++;
    }

    void removeBook(string ISBN) {
        for (int i = 0; i < count; i++) {
            if (isbns[i] == ISBN) {
                for (int j = i; j < count - 1; j++) {
                    books[j] = books[j + 1];
                    isbns[j] = isbns[j + 1];
                }
                count--;
                break;
            }
        }
    }

    Book* findBook(string ISBN) {
        for (int i = 0; i < count; i++) {
            if (isbns[i] == ISBN) {
                return books[i];
            }
        }
        return nullptr;
    }
};

class Library {
    Catalog catalog;
    Book* books[100];
    int bookCount;
public:
    Library() : bookCount(0) {}

    void addBook(Book* book) {
        books[bookCount] = book;
        catalog.addBook(book);
        bookCount++;
    }

    void removeBook(string ISBN) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getISBN() == ISBN) {
                for (int j = i; j < bookCount - 1; j++) {
                    books[j] = books[j + 1];
                }
                bookCount--;
                break;
            }
        }
        catalog.removeBook(ISBN);
    }

    void searchBook(string ISBN) {
        Book* book = catalog.findBook(ISBN);
        if (book)
            cout << "\nBook Found: " << book->getTitle() << endl;
        else
            cout << "\nBook Not Found" << endl;
    }
};

int main() {
    
    Library myLibrary;

    Book book1("Sherlock Holmes", "0123");
    Book book2("Rich Dad", "0000");

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);

    myLibrary.searchBook("0123");
    myLibrary.searchBook("1111");

    myLibrary.removeBook("0123");
    myLibrary.searchBook("0123");

    return 0;
}
