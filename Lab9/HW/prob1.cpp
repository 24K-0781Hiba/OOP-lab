#include <iostream>
using namespace std;

class Shape {
public:
    virtual float getArea() = 0;
};

class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float getArea() override {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    float base, height;
public:
    Triangle(float b, float h) : base(b), height(h) {}

    float getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    Rectangle r1(5.0, 3.0);
    Triangle t1(4.0, 6.0);
    cout << "Area of Rectangle: " << r1.getArea() << endl;
    cout << "Area of Triangle: " << t1.getArea() << endl;
    return 0;
}
