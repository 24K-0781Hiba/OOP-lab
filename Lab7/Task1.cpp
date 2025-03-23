#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;
    string accountHolderName;
    string accountType;
public:
    Account(string number, double initialBalance, string holderName, string type)
        : accountNumber(number), balance(initialBalance), accountHolderName(holderName), accountType(type) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balanve:/" << endl;
        }
    }

    virtual double calculateInterest() const {
        return 0.0;
    }

    virtual void printStatement() const {
        cout << "Account Statement for " << accountHolderName << " (" << accountNumber << "):" << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual void getAccountInfo() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string number, double initialBalance, string holderName, double rate, double minBalance)
        : Account(number, initialBalance, holderName, "Savings"), interestRate(rate), minimumBalance(minBalance) {}

    double calculateInterest() const override {
        return balance * interestRate / 100;
    }

    void withdraw(double amount) override {
        if (balance - amount >= minimumBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Withdrawal denied. Minimum balance requirement not met." << endl;
        }
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(string number, double initialBalance, string holderName)
        : Account(number, initialBalance, holderName, "Checking") {}

    void withdraw(double amount) override {
        Account::withdraw(amount);
    }
};

class FixedDepositAccount : public Account {
private:
    string maturityDate;
    double fixedInterestRate;

public:
    FixedDepositAccount(string number, double initialBalance, string holderName, string maturity, double fixedRate)
        : Account(number, initialBalance, holderName, "Fixed Deposit"), maturityDate(maturity), fixedInterestRate(fixedRate) {}

    double calculateInterest() const override {
        return balance * fixedInterestRate / 100;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal denied. Fixed deposit accounts have a maturity date." << endl;
    }
};

int main() {
    SavingsAccount savings("8898", 1000, "Michael Faraday", 2.5, 500);
    CheckingAccount checking("7268", 2000, "Erwin Smith");
    FixedDepositAccount fixedDeposit("7289", 5000, "Michael Faraday", "2025-12-31", 5.0);

    savings.deposit(500);
    savings.withdraw(200);
    savings.printStatement();

    checking.withdraw(2500);
    checking.printStatement();

    fixedDeposit.withdraw(1000);
    fixedDeposit.printStatement();

    return 0;
}
