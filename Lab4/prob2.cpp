#include <iostream>
using namespace std;
class Account {
private:
    double balance;
public:
    Account(double initialBalance) {
        balance =(initialBalance>=0) ? initialBalance : 0; 
    }
    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout<<""<<amount<<" added successfuly.\n";
        }
    }
    void debit(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout<<""<<amount<< " Withdrawn successfully.\n";
        } else {
            cout <<"Insufficient balance!"<<endl;
        }
    }
    double getBalance() const {
        return balance;
    }
};

int main() {
    Account acc(2000);
    acc.credit(350);
    acc.debit(400);
    cout<<"Current Balance is: "<<acc.getBalance()<<endl;
    return 0;
}

