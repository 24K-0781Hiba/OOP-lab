#include <iostream>
using namespace std;

template <typename T>
class Base {
protected:
    T a, b;

public:
    Base(T x, T y) : a(x), b(y) {}
    void multiplyBase() const {
        cout << "Base multiplication: " << (a * b) << endl;
    }
};

template <typename T>
class Derived : public Base<T> {
private:
    T c, d;
public:
    Derived(T x, T y, T z, T w) : Base<T>(x, y), c(z), d(w) {}

    void multiplyDerived() const {
        cout << "Derived multiplication: " << (c * d) << endl;
    }

    void showAllMultiplications() const {
        this->multiplyBase();
        this->multiplyDerived();
    }
};

int main() {
    Derived<int> obj(7, 3, 4, 5);
    obj.showAllMultiplications();
    Derived<float> obj2(1.5, 2.0, 3.5, 4.0);
    obj2.showAllMultiplications();
    return 0;
}
