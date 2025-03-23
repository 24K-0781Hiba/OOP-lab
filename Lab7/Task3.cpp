#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() const {
        return amount * exchangeRate;
    }

    virtual double convertTo(const Currency& targetCurrency) const {
        double baseAmount = convertToBase();
        return baseAmount / targetCurrency.exchangeRate;
    }

    virtual void displayCurrency() const {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() const override {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 0.92) {}

    void displayCurrency() const override {
        cout << "Amount: " << amount << currencySymbol << " (" << currencyCode << ")" << endl;
    }
};

class PakistaniRupee : public Currency {
public:
    PakistaniRupee(double amt) : Currency(amt, "PKR", "?", 280.0) {} //gotta be accurate here. 1 dollar=280 rupees

    void displayCurrency() const override {
        cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

int main() {
    Dollar usd(1000.50);
    Euro eur(1000.50);
    PakistaniRupee pkr(1000.50);

    Currency* currencies[] = { &usd, &eur, &pkr };

    for (Currency* currency : currencies) {
        currency->displayCurrency();
        cout << "Converted to base (USD): " << currency->convertToBase() << " USD" << endl;
        cout << "Converted to Euro: " << currency->convertTo(Euro(0)) << " EUR" << endl;
        cout << "Converted to Pakistani Rupee: " << currency->convertTo(PakistaniRupee(0)) << " PKR" << endl;
        cout << "-------------------------" << endl;
    }
    return 0;
}
