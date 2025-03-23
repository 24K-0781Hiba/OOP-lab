#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;

public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

    virtual void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
    }

    void checkOut() {
        cout << title << " has been checked out." << endl;
    }

    void returnItem() {
        cout << title << " has been returned." << endl;
    }

    string getTitle() const {
        return title;
    }

    string getPublicationDate() const {
        return publicationDate;
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

    string getAuthor() const {
        return author;
    }
};

class DVD : public Media {
private:
    string director;
    int duration; //in mins
    string rating;

public:
    DVD(string t, string pubDate, string id, string pub, string dir, int dur, string rate)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;
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
};

void searchByTitle(const Media& media, const string& title) {
    if (media.getTitle() == title) {
        media.displayInfo();
    }
}

void searchByAuthor(const Book& book, const string& author) {
    if (book.getAuthor() == author) {
        book.displayInfo();
    }
}

void searchByPublicationYear(const Media& media, const string& year) {
    if (media.getPublicationDate().substr(0, 4) == year) {
        media.displayInfo();
    }
}

int main() {
    Book book("The Great Gatsby", "1925-04-10", "B001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    DVD dvd("Inception", "2010-07-16", "D001", "Warner Bros.", "Christopher Nolan", 148, "PG-13");
    CD cd("Thriller", "1982-11-30", "C001", "Epic Records", "Michael Jackson", 9, "Pop");

    book.displayInfo();
    cout << "-------------------------" << endl;
    dvd.displayInfo();
    cout << "-------------------------" << endl;
    cd.displayInfo();
    cout << "-------------------------" << endl;

    book.checkOut();
    dvd.returnItem();
    //searching
    cout << "\nSearching for media by title 'Inception':" << endl;
    searchByTitle(dvd, "Inception");
    cout << "\nSearching for books by author 'F. Scott Fitzgerald':" << endl;
    searchByAuthor(book, "F. Scott Fitzgerald");
    cout << "\nSearching for media published in '1982':" << endl;
    searchByPublicationYear(cd, "1982");
    return 0;
}
