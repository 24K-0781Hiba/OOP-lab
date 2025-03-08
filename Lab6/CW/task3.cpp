#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
protected:
    int id;
    string name;

public:
    Employee(int empId, const string& empName)
        : id(empId), name(empName) {}

    virtual void display() const {
        cout << "Employee ID: " << id << ", Name: " << name << endl;
    }

    virtual ~Employee() = default;
};

class IOrderTaker {
public:
    virtual void takeOrder() = 0;
    virtual ~IOrderTaker() = default;
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
    virtual ~IOrderPreparer() = default;
};

class IBiller {
public:
    virtual void generateBill() = 0;
    virtual ~IBiller() = default;
};

//derived from employee and Iordertaker
class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int empId, const string& empName)
        : Employee(empId, empName) {}

    void takeOrder() override {
        cout << "Waiter " << name << " is taking the order." << endl;
    }

    void display() const override {
        cout << "Waiter - ";
        Employee::display();
    }
};
//derived frpm employee and iorderprepare
class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int empId, const string& empName)
        : Employee(empId, empName) {}

    void prepareOrder() override {
        cout << "Chef " << name << " is preparing the order." << endl;
    }

    void display() const override {
        cout << "Chef - ";
        Employee::display();
    }
};
//derived from employee and ibiller
class Cashier : public Employee, public IBiller {
public:
    Cashier(int empId, const string& empName)
        : Employee(empId, empName) {}

    void generateBill() override {
        cout << "Cashier " << name << " is generating the bill." << endl;
    }

    void display() const override {
        cout << "Cashier - ";
        Employee::display();
    }
};

//derived from multiple classes
class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int empId, const string& empName)
        : Employee(empId, empName) {}

    void takeOrder() override {
        cout << "Manager " << name << " is taking the order." << endl;
    }

    void generateBill() override {
        cout << "Manager " << name << " is generating the bill." << endl;
    }

    void display() const override {
        cout << "Manager - ";
        Employee::display();
    }
};

//base menu
class Menu {
protected:
    string name;
    double price;

public:
    Menu(const string& itemName, double itemPrice)
        : name(itemName), price(itemPrice) {}

    virtual double calculateTotalCost() const {
        return price;
    }

    virtual void display() const {
        cout << "Menu Item: " << name << ", Price: $" << price << endl;
    }

    virtual ~Menu() = default;
};

//derived from menu
class FoodMenu : public Menu {
public:
    FoodMenu(const string& itemName, double itemPrice)
        : Menu(itemName, itemPrice) {}

    double calculateTotalCost() const override {
        return price * 0.9;
    }

    void display() const override {
        cout << "Food Menu - ";
        Menu::display();
    }
};
//derived from menu
class BeverageMenu : public Menu {
public:
    BeverageMenu(const string& itemName, double itemPrice)
        : Menu(itemName, itemPrice) {}

    double calculateTotalCost() const override {
        return price * 1.05;
    }

    void display() const override {
        cout << "Beverage Menu - ";
        Menu::display();
    }
};

int main() {
    Waiter waiter(1, "John");
    Chef chef(2, "Alice");
    Cashier cashier(3, "Bob");
    Manager manager(4, "Eve");
    FoodMenu food("Burger", 10.0);
    BeverageMenu beverage("Soda", 2.0);

    vector<Employee*> employees = {&waiter, &chef, &cashier, &manager};
    vector<IOrderTaker*> orderTakers = {&waiter, &manager};
    vector<IBiller*> billers = {&cashier, &manager};

    cout << "Employee Details:" << endl;
    for (auto emp : employees) {
        emp->display();
    }
    cout << "\nTaking Orders:" << endl;
    for (auto orderTaker : orderTakers) {
        orderTaker->takeOrder();
    }
    cout << "\nGenerating Bills:" << endl;
    for (auto biller : billers) {
        biller->generateBill();
    }

    cout << "\nMenu Details:" << endl;
    vector<Menu*> menus = {&food, &beverage};
    for (auto menu : menus) {
        menu->display();
        cout << "Total Cost: $" << menu->calculateTotalCost() << endl;
    }
    return 0;
}
