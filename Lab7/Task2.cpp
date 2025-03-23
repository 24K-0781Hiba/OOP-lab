#include <iostream>
#include <string>
#include <cmath> //for pi adn sqrt etc

using namespace std;

class Shape {
protected:
    string color;
    pair<double, double> position;
    double borderThickness;

public:
    Shape(string col, pair<double, double> pos, double thickness = 1.0)
        : color(col), position(pos), borderThickness(thickness) {}

    virtual void draw() const {
        cout << "Drawing a shape at position (" << position.first << ", " << position.second << ") with color " << color << endl;
    }

    virtual double calculateArea() const {
        return 0.0;
    }

    virtual double calculatePerimeter() const {
        return 0.0;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(string col, pair<double, double> pos, double r, double thickness = 1.0)
        : Shape(col, pos, thickness), radius(r) {}

    void draw() const override {
        cout << "Drawing a circle at position (" << position.first << ", " << position.second << ") with radius " << radius << " and color " << color << endl;
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(string col, pair<double, double> pos, double w, double h, double thickness = 1.0)
        : Shape(col, pos, thickness), width(w), height(h) {}

    void draw() const override {
        cout << "Drawing a rectangle at position (" << position.first << ", " << position.second << ") with width " << width << ", height " << height << " and color " << color << endl;
    }

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(string col, pair<double, double> pos, double s1, double s2, double s3, double thickness = 1.0)
        : Shape(col, pos, thickness), side1(s1), side2(s2), side3(s3) {}

    void draw() const override {
        cout << "Drawing a triangle at position (" << position.first << ", " << position.second << ") with sides " << side1 << ", " << side2 << ", " << side3 << " and color " << color << endl;
    }

    double calculateArea() const override {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() const override {
        return side1 + side2 + side3;
    }
};

int main() {
    Circle circle("Red", {0, 0}, 5);
    Rectangle rectangle("Blue", {1, 1}, 4, 6);
    Triangle triangle("Green", {2, 2}, 3, 4, 5);

    Shape* shapes[] = {&circle, &rectangle, &triangle};

    for (Shape* shape : shapes) {
        shape->draw();
        cout << "Area: " << shape->calculateArea() << endl;
        cout << "Perimeter: " << shape->calculatePerimeter() << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}
