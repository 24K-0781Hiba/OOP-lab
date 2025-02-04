#include <iostream>
using namespace std;  //idk what to do here so I just added array's size to each element
void* modify(void* arr, int size) {
    int* intArr = static_cast<int*>(arr);  
    for (int i=0; i<size; i++) {
        *(intArr +i) += size; 
    }
    return arr; 
}
int main() {
    int size;
    cout<<"Enter array size: ";
    cin >>size;
    int* a =new int[size];  
    cout <<"Enter "<<size<< " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> *(a + i);
    }
    void* modifiedArr = modify(static_cast<void*>(a), size);  
    cout << "Modified array is: ";
    int* finalArr = static_cast<int*>(modifiedArr);
    for (int i=0; i<size; i++) {
        cout << *(finalArr + i) << " ";
    }
    cout <<endl;
    delete[] a;  
    return 0;
}

