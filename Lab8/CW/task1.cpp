#include <iostream>
using namespace std;

class fraction {
    private:
    int numerator;
    int denominator;

    public:
    fraction(int n, int d) : numerator(n), denominator(d) {
        if (denominator < 0){
                numerator = -numerator;
                denominator = -denominator;
        }
        if (denominator == 0){
            throw runtime_error("Denominator cannot be zero");
        }
        int gcd = 1;
        for (int i = 1; i <= numerator && i <= denominator; i++) {
            if (numerator % i == 0 && denominator % i == 0) {
                gcd = i;
            }
            numerator /= gcd;
            denominator /= gcd;            
        }
    }

    fraction operator +(const fraction &other) {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return fraction(newNumerator, newDenominator);
    }

    fraction operator -(const fraction &other) {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return fraction(newNumerator, newDenominator);
    }

    fraction operator *(const fraction &other) {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return fraction(newNumerator, newDenominator);
    }

    fraction operator /(const fraction &other) {
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.denominator;
        return fraction(newNumerator, newDenominator);
    }

    bool operator ==(const fraction &other) {
        return (numerator * other.denominator == other.numerator * denominator);
    }

    bool operator !=(const fraction &other) {
        return (numerator * other.denominator != other.numerator * denominator);
    }

    bool operator <(const fraction &other) {
        if (numerator * other.denominator < other.numerator * denominator) {
            return true;
        }
    }

    bool operator >(const fraction &other) {
        if (numerator * other.denominator > other.numerator * denominator) {
            return true;
        }
    }

    bool operator <=(const fraction &other) {
        if (numerator * other.denominator <= other.numerator * denominator) {
            return true;
        }
    }

    bool operator >=(const fraction &other) {
        if (numerator * other.denominator >= other.numerator * denominator) {
            return true;
        }
    }

    friend std::ostream& operator <<(std::ostream &os, const fraction &f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
    friend std::istream& operator >>(std::istream &is, fraction &f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        return is;
    }

    void display(){
        cout << numerator << "/" << denominator << endl;
    }

};

int main() {
    fraction f1(1, 7);
    fraction f2(1, -3);
    fraction f3 = f1 + f2;
    f3.display();
    fraction f4 = f1 - f2;
    f4.display();
    fraction f5 = f1 * f2;
    f5.display();
    fraction f6 = f1 / f2;
    f6.display();

    return 0;
}
