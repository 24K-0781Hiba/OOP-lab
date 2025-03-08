#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance; //declaring them as protected instead of private so that they're at east accessible
public:
    BankAccount(string accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}
    
    //virtual funcs
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << " into account " << accountNumber << ". New balance: $" << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from account " << accountNumber << ". New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds in account " << accountNumber << " to withdraw $" << amount << endl;
        }
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }

    //getter
    string getAccountNumber() const {
        return accountNumber;
    }

    virtual ~BankAccount() = default; //virtual default destructor since apparently it's good practice
};

//derived from bankAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, double initialBalance, double rate)
        : BankAccount(accNum, initialBalance), interestRate(rate) {}

    void applyMonthlyInterest() {
        double interest = balance * (interestRate / 100);
        deposit(interest);
        cout << "Applied monthly interest of $" << interest << " to account " << accountNumber << endl;
    }

    void display() const override {
        cout << "Savings Account - ";
        BankAccount::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

//derived from bankAccount
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNum, double initialBalance, double limit)
        : BankAccount(accNum, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from account " << accountNumber << ". New balance: $" << balance << endl;
            if (balance < 0) {
                cout << "ALERT: Overdraft limit exceeded for account " << accountNumber << endl;
            }
        } else {
            cout << "Withdrawal denied. Overdraft limit exceeded for account " << accountNumber << endl;
        }
    }

    void display() const override {
        cout << "Checking Account - ";
        BankAccount::display();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

//derived from bankAccount
class BusinessAccount : public BankAccount {
private:
    double corporateTaxRate;

public:
    BusinessAccount(string accNum, double initialBalance, double taxRate)
        : BankAccount(accNum, initialBalance), corporateTaxRate(taxRate) {}

    void deposit(double amount) override {
        double tax = amount * (corporateTaxRate / 100);
        double netAmount = amount - tax;
        balance += netAmount;
        cout << "Deposited $" << netAmount << " (after $" << tax << " corporate tax) into account " << accountNumber << ". New balance: $" << balance << endl;
    }

    void display() const override {
        cout << "Business Account - ";
        BankAccount::display();
        cout << "Corporate Tax Rate: " << corporateTaxRate << "%" << endl;
    }
};

//another base class
class UserRole {
public:
    virtual void performOperations(BankAccount* account) = 0;
    virtual ~UserRole() = default;
};

//derived from userRole
class Customer : public UserRole {
public:
    void performOperations(BankAccount* account) override {
        cout << "Customer performing operations:" << endl;
        account->deposit(100);
        account->withdraw(50);
    }
};

//derived from userRole too
class Teller : public UserRole {
public:
    void performOperations(BankAccount* account) override {
        cout << "Teller performing operations:" << endl;
        account->deposit(200);
        account->withdraw(100);
        cout << "Teller froze account " << account->getAccountNumber() << " for maintenance." << endl;
    }
};

//derived from userRole too
class Manager : public UserRole {
public:
    void performOperations(BankAccount* account) override {
        cout << "Manager performing operations:" << endl;
        account->deposit(500);
        account->withdraw(300);
        cout << "Manager adjusted overdraft limit for account " << account->getAccountNumber() << "." << endl;
    }
};

int main() {
    //creating diff accounts
    SavingsAccount savings("SA001", 1000, 1.5);
    CheckingAccount checking("CA001", 500, 200);
    BusinessAccount business("BA001", 10000, 10);

    //making users
    Customer customer;
    Teller teller;
    Manager manager;

    vector<BankAccount*> accounts = {&savings, &checking, &business};
    vector<UserRole*> roles = {&customer, &teller, &manager};

    for (auto account : accounts) {
        cout << "----------------------------------------" << endl;
        account->display();
        for (auto role : roles) {
            role->performOperations(account);
            account->display();
        }
        cout << "----------------------------------------" << endl;
    }
    return 0;
}
