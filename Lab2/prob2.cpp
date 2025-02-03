#include <iostream>
using namespace std;  //idk what to do here so I just added array's size to each element
void modify(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) += size; 
    }
}

int main() {
    int size, i;
    cout<<"Enter array size: ";
    cin >>size;
    int* a= new int[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >>*(a+i);
    }
    modify(a, size);
    cout << "Modified array: ";
    for (i=0; i<size; i++) {
        cout <<*(a+ i) << " ";
    }
    cout<< endl;
    delete[] a;
    return 0;
}

