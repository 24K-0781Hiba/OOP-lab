#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Book {
public:
    string title;
    string author;
    string publisher;
    double price;
    int stock;
    Book(string t, string a, string p, double pr, int s)
        : title(t), author(a), publisher(p), price(pr), stock(s) {}
    bool isAvailable(int quantity) const {
        return stock >= quantity;
    }
    double sellBook(int quantity) {
        if (isAvailable(quantity)) {
            stock -= quantity;
            return price * quantity;
        } else {
            cout << "Required copies not in stock." << endl;
            return 0.0;
        }
    }
};

class Bookshop {
private:
    vector<Book> inventory;

public:
    void addBook(const Book& book) {
        inventory.push_back(book);
    }

    void searchBook(string t, string a) {
        for (auto& book : inventory) { 
            if (book.title == t && book.author == a) {
                cout << "Book Found!" << endl;
                cout << "Title: " << book.title << "\nAuthor: " << book.author
                     << "\nPublisher: " << book.publisher << "\nPrice: $" << book.price
                     << "\nStock: " << book.stock << endl;

                int quantity;
                cout << "Enter number of copies required: ";
                cin >> quantity;

                double cost = book.sellBook(quantity); 
                if (cost > 0) {
                    cout << "Total Cost: $" << cost << endl;
                }
                return;
            }
        }
        cout << "Book not available in the inventory." << endl;
    }
};

int main() {
    Bookshop shop;
    shop.addBook(Book("The Alchemist", "Paulo Coelo", "HarperCollins", 50.0, 10));
    shop.addBook(Book("The silent Patient", "Alex Michaelides", "Machmillan", 40.0, 5));
    string title, author;
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, author);
    shop.searchBook(title, author);
    return 0;
}

