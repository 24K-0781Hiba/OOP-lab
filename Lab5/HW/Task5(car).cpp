#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    mutable int engine_horsepower; //we use mutable if wewant to change via a const func
    mutable int seating_capacity;
    mutable int no_of_speakers;

    Car(int hp, int seats, int speakers)
        : engine_horsepower(hp), seating_capacity(seats), no_of_speakers(speakers) {}

    void modifyAttributes(int hp, int seats, int speakers) const {
        engine_horsepower = hp; 
        seating_capacity = seats;
        no_of_speakers = speakers;
    }

    void display() const {
        cout << "Engine Horsepower: " << engine_horsepower << endl;
        cout << "Seating Capacity: " << seating_capacity << endl;
        cout << "Number of Speakers: " << no_of_speakers << endl;
    }
};

int main() {
    Car myCar(154, 5, 4);
    cout << "Initial Car Details:" << endl;
    myCar.display();

    myCar.modifyAttributes(210, 7, 3);
    cout << "\nUpdated Car Details:" << endl;
    myCar.display();
    return 0;
}
