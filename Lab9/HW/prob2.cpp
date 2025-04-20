#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    float price;

public:
    Car(string m) : model(m), price(0) {}

    void setModel(string m) {
        model = m;
    }

    string getModel() const {
        return model;
    }

    float getPrice() const {
        return price;
    }

    virtual void setPrice(float p) = 0;
};

class Color : public Car {
private:
    string color;
public:
    Color(string m, string c) : Car(m), color(c) {}

    void setPrice(float p) override {
        price = p;
    }

    string getColor() const {
        return color;
    }

    void display() {
        cout << "Model: " << model << ", Color: " << color << ", Price: $" << price << endl;
    }
};

class Company : public Car {
private:
    string companyName;
public:
    Company(string m, string cName) : Car(m), companyName(cName) {}

    void setPrice(float p) override {
        price = p;
    }

    string getCompanyName() const {
        return companyName;
    }

    void display() {
        cout << "Model: " << model << ", Company: " << companyName << ", Price: $" << price << endl;
    }
};

int main() {
    Color c1("Model X", "Red");
    c1.setPrice(55000);
    c1.display();
    Company c2("Model Y", "Honda");
    c2.setPrice(85000);
    c2.display();

    return 0;
}
