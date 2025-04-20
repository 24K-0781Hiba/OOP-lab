#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Wallet {
private:
    double balance;
    double dailyDepositLimit;
    double dailyWithdrawalLimit;
    double depositedToday;
    double withdrawnToday;

public:
    Wallet(double depositLimit = 10000.0, double withdrawalLimit = 5000.0)
        : balance(0), dailyDepositLimit(depositLimit), dailyWithdrawalLimit(withdrawalLimit),
          depositedToday(0), withdrawnToday(0) {}

    bool deposit(double amount) {
        if (amount <= 0) {
            cout << "Error: Deposit amount must be positive\n";
            return false;
        }

        if (depositedToday + amount > dailyDepositLimit) {
            cout << "Error: Exceeds daily deposit limit ($" << dailyDepositLimit << ")\n";
            return false;
        }

        balance += amount;
        depositedToday += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive\n";
            return false;
        }

        if (amount > balance) {
            cout << "Error: Insufficient funds\n";
            return false;
        }

        if (withdrawnToday + amount > dailyWithdrawalLimit) {
            cout << "Error: Exceeds daily withdrawal limit ($" << dailyWithdrawalLimit << ")\n";
            return false;
        }

        balance -= amount;
        withdrawnToday += amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }

    void resetDailyLimits() {
        depositedToday = 0;
        withdrawnToday = 0;
    }
};

class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(const string& id, const string& userName) 
        : userID(id), name(userName) {}

    void deposit(double amount) {
        wallet.deposit(amount);
    }

    void withdraw(double amount) {
        wallet.withdraw(amount);
    }

    double checkBalance() const {
        return wallet.getBalance();
    }

    string getID() const {
        return userID;
    }

    string getName() const {
        return name;
    }

    void resetDailyLimits() {
        wallet.resetDailyLimits();
    }
};

int main() {
    User alice("A123", "Alice");
    User bob("B789", "Bob");

    cout << "Initial balances:\n";
    cout << "Alice: $" << alice.checkBalance() << endl;
    cout << "Bob: $" << bob.checkBalance() << endl;

    cout << "\nAlice deposits $500\n";
    alice.deposit(500);
    cout << "Alice's balance: $" << alice.checkBalance() << endl;

    cout << "\nBob deposits $1000\n";
    bob.deposit(1000);
    cout << "Bob's balance: $" << bob.checkBalance() << endl;

    cout << "\nAlice withdraws $200\n";
    alice.withdraw(200);
    cout << "Alice's balance: $" << alice.checkBalance() << endl;

    //testing error cases
    cout << "\nAlice attempts to withdraw $400 (more than balance)\n";
    alice.withdraw(400);
    cout << "Alice's balance remains: $" << alice.checkBalance() << endl;

    cout << "\nBob attempts to deposit $-100 (negative amount)\n";
    bob.deposit(-100);
    cout << "Bob's balance remains: $" << bob.checkBalance() << endl;

    cout << "\nAlice attempts to deposit $20000 (exceeds daily limit)\n";
    alice.deposit(20000);
    cout << "Alice's balance remains: $" << alice.checkBalance() << endl;

    cout << "\nBob attempts to withdraw $6000 (exceeds daily limit)\n";
    bob.withdraw(6000);
    cout << "Bob's balance remains: $" << bob.checkBalance() << endl;

    cout << "\nResetting daily limits...\n";
    alice.resetDailyLimits();
    bob.resetDailyLimits();

    cout << "\nFinal balances:\n";
    cout << "Alice: $" << alice.checkBalance() << endl;
    cout << "Bob: $" << bob.checkBalance() << endl;
    return 0;
}
