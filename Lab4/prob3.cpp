#include <iostream>
#include <string>  
using namespace std;
class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(string pNumber, string pDescription, int quan, double price) {
        partNumber = pNumber;
        partDescription = pDescription;
        quantity = (quan>0) ? quan : 0;  
        pricePerItem = (price>0) ? price : 0.0; 
    }
    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
    void displayInvoice() const {
        cout <<"Part Number: " <<partNumber <<endl;
        cout<<"Part Description: " <<partDescription <<endl;
        cout<<"Quantity: " <<quantity <<endl;
        cout<<"Price per Item: $" <<pricePerItem <<endl;
        cout<<"Total Invoice Amount: $" <<getInvoiceAmount() <<endl;
    }
};
int main() {
    Invoice invoice1("XYZ2025", "TV", 10, 20.75);
    invoice1.displayInvoice();
    return 0;
}

