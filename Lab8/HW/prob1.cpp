#include<iostream>
#include<string>
#include<vector>
using namespace std;

class number {
    double value;
public:
    number(double v) : value(v) {}
    //prefix
    number& operator--() {
        value *= 4;
        return *this;
    }
    //postfix
    number operator--(int) {
        number temp = *this;
        value /= 4;
        return temp;
    }
    
    double getV() { return value; }
    
    void display() {
        cout << value << endl;
    }
};
int main() {
    number n(16);

    cout << "Original value of n: ";
    n.display();

    //prefix
    cout << "\nPre fixing\n";
    --n;
    cout << "After --n (expect 16 * 4 = 64): ";
    n.display();
 
    //postfix
    //postfix
    cout<< "\npost fixing\n";
    cout << "Returned value of n-- (expect 64): ";
    n--.display();
    cout << "New value of n after n-- (expect 64 / 4 = 16): ";
    n.display();

    return 0;
}
