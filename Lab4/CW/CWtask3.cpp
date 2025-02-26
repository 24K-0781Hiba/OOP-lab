#include <iostream>
#include <algorithm> 
using namespace std;

class DynamicArray {
private:
    int* data;    
    int size_;      

public:
    DynamicArray() : data(nullptr), size_(0) {}

    //parameterized constructor
    DynamicArray(int n) : size_(n) {
        if (n > 0) {
            data = new int[n]();
        } else {
            data = nullptr;
            size_ = 0;
        }
    }

    //copy constructor
    DynamicArray(const DynamicArray& other) : size_(other.size_) {
        if (other.data) {
            data = new int[size_];
            copy(other.data, other.data + size_, data); 
        } else {
            data = nullptr;
        }
    }

    //move constructor
    DynamicArray(DynamicArray&& other) noexcept : data(other.data), size_(other.size_) {
        other.data = nullptr; 
        other.size_ = 0;
    }

    //destructot
    ~DynamicArray() {
        delete[] data;
    }

    //copy assignment operator
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this;

        delete[] data;
        size_ = other.size_;
        if (other.data) {
            data = new int[size_];
            copy(other.data, other.data + size_, data); 
        } else {
            data = nullptr;
        }

        return *this;
    }

    //move assignment operator
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this == &other) return *this; 

        delete[] data; 

        data = other.data; 
        size_ = other.size_;

        other.data = nullptr; 
        other.size_ = 0;

        return *this;
    }
    int size() const {
        return size_;
    }

    int& at(int index) {
        if (index < 0 || index >= size_) {
            cerr << "Error: Index out of bounds." << endl;
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }
    //for read onlu access
    const int& at(int index) const {
        if (index < 0 || index >= size_) {
            cerr << "Error: Index out of bounds." << endl;
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    //resixing
    void resize(int newSize) {
        if (newSize < 0) {
            cerr << "Error: New size cannot be negative." << endl;
            return;
        }

        if (newSize == size_) return; 

        int* newData = new int[newSize](); 
        if (data) {
            int elementsToCopy = min(size_, newSize);
            copy(data, data + elementsToCopy, newData); 
            delete[] data; 
        }
        data = newData;
        size_ = newSize;
    }

    //for printing
    void print() const {
        for (int i = 0; i < size_; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr1(5);
    cout << "Array 1 (size " << arr1.size() << "): ";
    arr1.print();
    arr1.at(2) = 10;
    cout << "Array 1 after modification: ";
    arr1.print();
    DynamicArray arr2 = arr1; 
    cout << "Array 2 (copy of Array 1): ";
    arr2.print();
    DynamicArray arr3 = move(arr1);
    cout << "Array 3 (moved from Array 1): ";
    arr3.print();
    cout << "Array 1 after move (should be empty): ";
    arr1.print();
    arr3.resize(8);
    cout << "Array 3 after resize to 8: ";
    arr3.print();
    DynamicArray arr4;
    arr4 = arr3;
    cout << "Array 4 (copy of Array 3): ";
    arr4.print();
    DynamicArray arr5;
    arr5 = move(arr3);
    cout << "Array 5 (moved from Array 3): ";
    arr5.print();
    cout << "Array 3 after move (should be empty): ";
    arr3.print();
    return 0;
}
