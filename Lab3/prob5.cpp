#include <iostream>
using namespace std;
class Book {
private:
    string bookName;
    string ISBN;
    string authorName;
    string publisher;
public:
    Book(string bookName, string ISBN, string authorName, string publisher) {
        this->bookName = bookName;
        this->ISBN = ISBN;
        this->authorName = authorName;
        this->publisher = publisher;
    }
    string getBookName() {
	    return this->bookName; 
	}
    string getISBN() {
	    return this->ISBN; 
	}
    string getAuthorName() {
	    return this->authorName; 
	}
    string getPublisher() {
	    return this->publisher; 
	}
    string getBookInfo() {
        return "Book: " +this->bookName+ "\nISBN: " +this->ISBN+"\nAuthor: " +this->authorName+ "\nPublisher: " +this->publisher+ "\n";
    }
};
int main() {
    Book books[5] = {
        Book("The Great Gatsby", "9780743273565", "F. Scott Fitzgerald", "Scribner"),
        Book("1984", "9780451524935", "George Orwell", "Signet Classic"),
        Book("Little Women", "9780147514011", "Louisa May Alcott", "Penguin Classics"),
        Book("No Longer Human", "9780811204811", "Osamu Dazai", "New Directions"),
        Book("Pride and Prejudice", "9780141439518", "Jane Austen", "Penguin Classics")
    };
    cout << "Book List:\n\n";
    for (int i=0; i<5; i++) {
        cout<<books[i].getBookInfo()<<endl;
    }
    return 0;
}

