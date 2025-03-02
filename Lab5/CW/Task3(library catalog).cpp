#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Library;

class Book {
private:
    string title;
    string author;
    string isbn;

public:
    Book(const string& title, const string& author, const string& isbn)
        : title(title), author(author), isbn(isbn) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }

    void print() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << endl;
    }
};

class Catalog {
private:
    vector<pair<string, string>> isbnToLocation; 

public:
    void addBook(const string& isbn, const string& location) {
        isbnToLocation.push_back(make_pair(isbn, location));
    }
    void removeBook(const string& isbn) {
        for (auto it = isbnToLocation.begin(); it != isbnToLocation.end(); ++it) {
            if (it->first == isbn) {
                isbnToLocation.erase(it);
                break;
            }
        }
    }
    string findBookLocation(const string& isbn) const {
        for (const auto& entry : isbnToLocation) {
            if (entry.first == isbn) {
                return entry.second;
            }
        }
        return "Book not found in catalog!";
    }
    void print() const {
        for (const auto& entry : isbnToLocation) {
            cout << "ISBN: " << entry.first << ", Location: " << entry.second << endl;
        }
    }
};
class Library {
private:
    string name;
    string address;
    Catalog catalog; 
    vector<Book*> books; 

public:
    Library(const string& name, const string& address)
        : name(name), address(address) {}
    ~Library() {
        for (auto book : books) {
            delete book;
        }
    }

    void addBook(const string& title, const string& author, const string& isbn, const string& location) {
        Book* book = new Book(title, author, isbn); 
        books.push_back(book);
        catalog.addBook(isbn, location);
    }
    void removeBook(const string& isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->getISBN() == isbn) {
                delete *it; 
                books.erase(it);
                catalog.removeBook(isbn);
                cout << "Book with ISBN " << isbn << " removed from the library." << endl;
                return;
            }
        }
        cout << "Book with ISBN " << isbn << " not found in the library." << endl;
    }

    string findBookInCatalog(const string& isbn) const {
        return catalog.findBookLocation(isbn);
    }
    void printBooks() const {
        cout << "Books in " << name << ":" << endl;
        for (const auto& book : books) {
            book->print();
        }
    }

    void printCatalog() const {
        cout << "Catalog of " << name << ":" << endl;
        catalog.print();
    }
};

int main() {

    Library library("Central Library", "123 Library St");

    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", "Fiction Section, Shelf 1");
    library.addBook("1984", "George Orwell", "9780451524935", "Fiction Section, Shelf 2");
    library.addBook("To Kill a Mockingbird", "Harper Lee", "9780061120084", "Fiction Section, Shelf 3");

    library.printBooks();

    library.printCatalog();

    string isbnToSearch = "9780451524935";
    cout << "Searching for book with ISBN " << isbnToSearch << ": "
         << library.findBookInCatalog(isbnToSearch) << endl;

    library.removeBook("9780743273565");

    library.printCatalog();
    return 0;
}
