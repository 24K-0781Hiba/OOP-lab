#include <iostream>
using namespace std;

int main() {
    int i, n = 5;
    int choice, count = 0;
    int *a = new int[n];
    cout << "Enter " << n << " elements for the 1D array:\n";
    for (i = 0; i < n; i++) {
        cin >> a[i];
        count++; 
    }
    while (true) {
        cout << "Do you want to add another element? (1 for yes, 0 for no): ";
        cin >> choice;
        if (choice==0) break;
        if (count >= n) {
            n *=2;
            int *temp = new int[n];
            for (i = 0; i < count; i++) {
                temp[i] = a[i];
            }
            delete[] a; 
            a = temp;   
        }
        cout << "Enter element: ";
        cin >> a[count];
        count++; 
    }
    int *finalArray = new int[count];
    for (i = 0; i < count; i++) {
        finalArray[i] = a[i];
    }
    delete[] a; 
    a = finalArray;
    cout << "Final array is: ";
    for (i = 0; i < count; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a; 
    return 0;
}

