#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    virtual void getdata() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
    }

    virtual void displaydata() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }

    virtual void bonus() = 0;
};

class Admin : virtual public Person {
protected:
    float adminSalary;
public:
    void getdata() override {
        Person::getdata();
        cout << "Enter Admin salary: ";
        cin >> adminSalary;
    }

    void displaydata() override {
        Person::displaydata();
        cout << "Admin Salary: " << adminSalary << endl;
    }

    void bonus() override {
        cout << "Admin Bonus: $" << (adminSalary * 0.10) << endl;
    }
};

class Account : virtual public Person {
protected:
    float accountSalary;
public:
    void getdata() override {
        Person::getdata();
        cout << "Enter Account salary: ";
        cin >> accountSalary;
    }

    void displaydata() override {
        Person::displaydata();
        cout << "Account Salary: " << accountSalary << endl;
    }

    void bonus() override {
        cout << "Account Bonus: $" << (accountSalary * 0.12) << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getdata() override {
        Admin::getdata();
        cout << "Enter combined salary for Master (Admin + Account): ";
        cin >> adminSalary >> accountSalary;
    }

    void displaydata() override {
        Person::displaydata();
        cout << "Admin Salary: " << adminSalary << ", Account Salary: " << accountSalary << endl;
    }

    void bonus() override {
        float total = (adminSalary * 0.10) + (accountSalary * 0.12);
        cout << "Master Bonus (combined): $" << total << endl;
    }
};

int main() {
    Person* emp;
    Master m;
    emp = &m;
    cout << "--- Enter Master Employee Data ---" << endl;
    emp->getdata();
    cout << "\n--- Display Master Employee Data ---" << endl;
    emp->displaydata();
    cout << "\n--- Calculating Bonus ---" << endl;
    emp->bonus();
    return 0;
}
