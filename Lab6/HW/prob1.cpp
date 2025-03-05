#include <iostream>
#include <string>
using namespace std;

class Books {
public:
    string genre;
};

class Novel : public Books {
public:
    string title; 
    string author;
};

class Mystery : public Books {
public:
    string title;
    string author; 
};

int main() {
    Novel novelBook;
    novelBook.genre = "Novel";
    novelBook.title = "To Kill a Mockingbird";
    novelBook.author = "Harper Lee";

    Mystery mysteryBook;
    mysteryBook.genre = "Mystery";
    mysteryBook.title = "The Girl with the Dragon Tattoo";//personal fav
    mysteryBook.author = "Stieg Larsson";
    //display novel
    cout << "Novel Book Details:" << endl;
    cout << "Genre: " << novelBook.genre << endl;
    cout << "Title: " << novelBook.title << endl;
    cout << "Author: " << novelBook.author << endl;
    cout << endl;
    //diplay mystery
    cout << "Mystery Book Details:" << endl;
    cout << "Genre: " << mysteryBook.genre << endl;
    cout << "Title: " << mysteryBook.title << endl;
    cout << "Author: " << mysteryBook.author << endl;

    return 0;
}
