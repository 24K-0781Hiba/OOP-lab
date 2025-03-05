#include <iostream>
using namespace std;

class Vehicles {
public:
    double price;
};

class Car : public Vehicles {
public:
    int seatingCapacity;
    int numberOfDoors;
    string fuelType;
};

class Motorcycle : public Vehicles {
public:
    int numberOfCylinders;
    int numberOfGears;
    int numberOfWheels;
};

class Audi : public Car {
public:
    string modelType;
};

class Yamaha : public Motorcycle {
public:
    string makeType;
};

int main() {
    // Audi object
    Audi audiCar;
    audiCar.price = 290000; //why is there so much typing in oop 
    audiCar.seatingCapacity = 5;
    audiCar.numberOfDoors = 4;
    audiCar.fuelType = "Petrol";
    audiCar.modelType = "A4";
    // Yamaha object
    Yamaha yamahaBike;
    yamahaBike.price = 10000;
    yamahaBike.numberOfCylinders = 2;
    yamahaBike.numberOfGears = 5;
    yamahaBike.numberOfWheels = 2;
    yamahaBike.makeType = "YZF-R1";
    // Displaying Audi details
    cout << "Audi Car Details:\n";
    cout << "Price: $" << audiCar.price << "\n";
    cout << "Seating Capacity: " << audiCar.seatingCapacity << "\n";
    cout << "Number of Doors: " << audiCar.numberOfDoors << "\n";
    cout << "Fuel Type: " << audiCar.fuelType << "\n";
    cout << "Model Type: " << audiCar.modelType << "\n\n";
    // Displaying Yamaha details
    cout << "Yamaha Motorcycle Details:\n";
    cout << "Price: $" << yamahaBike.price << "\n";
    cout << "Number of Cylinders: " << yamahaBike.numberOfCylinders << "\n";
    cout << "Number of Gears: " << yamahaBike.numberOfGears << "\n";
    cout << "Number of Wheels: " << yamahaBike.numberOfWheels << "\n";
    cout << "Make Type: " << yamahaBike.makeType << "\n";
    return 0;
}
