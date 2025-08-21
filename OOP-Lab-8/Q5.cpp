#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Media {
    protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;
    bool isCheckedOut;

    public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    virtual void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is already checked out." << endl;
        }
    }

    virtual void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not checked out." << endl;
        }
    }

    virtual ~Media() {}

    virtual bool searchByTitle(const string &searchTerm) const {
        return title.find(searchTerm) != string::npos;
    }

    virtual bool searchByPublisher(const string &searchTerm) const {
        return publisher.find(searchTerm) != string::npos;
    }

    virtual bool searchByPublicationDate(const string &searchTerm) const {
        return publicationDate.find(searchTerm) != string::npos;
    }
};

class Book : public Media {
    private:
    string author;
    string ISBN;
    int numberOfPages;

    public:
    Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }

    bool searchByAuthor(const string &searchTerm) const {
        return author.find(searchTerm) != string::npos;
    }
};

class DVD : public Media {
    private:
    string director;
    int duration;
    double rating;

    public:
    DVD(string t, string pubDate, string id, string pub, string dir, int dur, double rate)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << " / 10" << endl;
    }

    bool searchByDirector(const string &searchTerm) const {
        return director.find(searchTerm) != string::npos;
    }
};

class CD : public Media {
    private:
    string artist;
    int numberOfTracks;
    string genre;

    public:
    CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }

    bool searchByArtist(const string &searchTerm) const {
        return artist.find(searchTerm) != string::npos;
    }
};

class Magazine : public Media {
    private:
    string issueNumber;
    string category;

    public:
    Magazine(string t, string pubDate, string id, string pub, string issue, string cat)
        : Media(t, pubDate, id, pub), issueNumber(issue), category(cat) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Category: " << category << endl;
    }
};

int main() {
    Book book1("The C++ Programming Language", "2013", "B001", "Addison-Wesley", "Bjarne Stroustrup", "9780321563842", 1368);
    DVD dvd1("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD cd1("Thriller", "1982", "C001", "Epic Records", "Michael Jackson", 9, "Pop");
    Magazine mag1("National Geographic", "April 2024", "M001", "National Geographic Society", "Vol. 239", "Science");

    vector<Media*> mediaCollection;
    mediaCollection.push_back(&book1);
    mediaCollection.push_back(&dvd1);
    mediaCollection.push_back(&cd1);
    mediaCollection.push_back(&mag1);

    for (const auto &media : mediaCollection) {
        media->displayInfo();
        cout << "-------------------------" << endl;
    }

    return 0;
}
