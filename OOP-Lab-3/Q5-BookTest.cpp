#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    Book books[5] =  {
        Book("The Great Gatsby", "9780743273565", "F. Scott Fitzgerald", "Scribner"),
        Book("1984", "9780451524935", "George Orwell", "Harvill Secker"),
        Book("To Kill a Mockingbird", "9780061120084", "Harper Lee", "J.B. Lippincott & Co."),
        Book("The Catcher in the Rye", "9780316769488", "J.D. Salinger", "Little, Brown and Company"),
        Book("Moby-Dick", "9781503280786", "Herman Melville", "Harper & Brothers")
    };


    for (int i = 0; i < 5; i++) {
        cout << "Details of Book " << i+1 << ":" << endl;
        books[i].getBookInfo();
    }
}