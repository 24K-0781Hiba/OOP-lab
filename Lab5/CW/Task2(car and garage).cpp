#include <iostream>
#include <vector>
using namespace std;

class Car {
    string name;
    int id;
public:
    Car(string carName, int carID) : name(carName), id(carID) {
        cout << "Car " << name << " (ID: " << id << ") created.\n";
    }
    ~Car() {
        cout << "Car " << name << " (ID: " << id << ") destroyed.\n";
    }

    void display() const {
        cout << "Car Name: " << name << ", ID: " << id << endl;
    }
    int getID() const { return id; }
    string getName() const { return name; }
};

class Garage {
    vector<Car*> cars;

public:
    void parkCar(Car* car) {
        if (car) {
            cars.push_back(car);
            cout << "Parked " << car->getName() << " (ID: " << car->getID() << ") in the garage.\n";
        }
    }
    void listCars() const {
        cout << "Cars currently in the garage:\n";
        if (cars.empty()) {
            cout << "No cars parked.\n";
            return;
        }
        for (const auto& car : cars) {
            cout << "- " << car->getName() << " (ID: " << car->getID() << ")\n";
        }
    }
};

int main() {
    cout << "Creating cars on the stack...\n"; 
    Car car1("Toyota", 101);
    Car car2("Honda", 102);
    Car car3("Ford", 103);

    cout << "\nCreating a Garage...\n";
    Garage garage;
    cout << "\nParking cars...\n";
    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);
    cout << "\nListing cars in garage:\n";
    garage.listCars();
    cout << "\nDemonstrating potential issue:\n";
    {
        Car tempCar("Temporary", 999);
        garage.parkCar(&tempCar);
        cout << "Garage now contains:\n";
        garage.listCars();
    } //temp car gone. dangling pointer
    cout << "\nListing cars in garage after tempCar is destroyed:\n";
    garage.listCars(); 

    cout << "\nMain function ending...\n";
    return 0;
}
