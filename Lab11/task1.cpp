#include <iostream>
#include <stdexcept>
using namespace std;

class ArrayIndexOutOfBounds : public out_of_range {
public:
    ArrayIndexOutOfBounds(const string& message) 
        : out_of_range(message) {}
};

template <typename T>
class SafeArray {
private:
    T* data;
    size_t size;

public:
    SafeArray(size_t size) : size(size) {
        data = new T[size](); // Value initialization
    }

    ~SafeArray() {
        delete[] data;
    }

    SafeArray(const SafeArray& other) : size(other.size) {
        data = new T[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    SafeArray& operator=(const SafeArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    T& operator[](int index) {
        checkBounds(index);
        return data[index];
    }

    const T& operator[](int index) const {
        checkBounds(index);
        return data[index];
    }
    size_t getSize() const {
        return size;
    }

private:
    void checkBounds(int index) const {
        if (index < 0 || static_cast<size_t>(index) >= size) {
            throw ArrayIndexOutOfBounds(
                "Index " + to_string(index) + 
                " is out of bounds for array of size " + 
                to_string(size));
        }
    }
};

// Demo program
int main() {
    try {
        SafeArray<int> intArray(5);

        for (int i = 0; i < intArray.getSize(); ++i) {
            intArray[i] = i * 10;
        }

        cout << "Array contents: ";
        for (int i = 0; i < intArray.getSize(); ++i) {
            cout << intArray[i] << " ";
        }
        cout << endl;

        cout << "Element at index 2: " << intArray[2] << endl;

        //testing invalid access
        try {
            cout << "Element at index -1: " << intArray[-1] << endl;
        } catch (const ArrayIndexOutOfBounds& e) {
            cerr << "Error: " << e.what() << endl;
        }

        //testing invalid access
        try {
            cout << "Element at index 10: " << intArray[10] << endl;
        } catch (const ArrayIndexOutOfBounds& e) {
            cerr << "Error: " << e.what() << endl;
        }

        SafeArray<string> strArray(3);
        strArray[0] = "Hello";
        strArray[1] = "World";
        strArray[2] = "!";

        cout << "String array: ";
        for (int i = 0; i < strArray.getSize(); ++i) {
            cout << strArray[i] << " ";
        }
        cout << endl;

    } catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
