#include <iostream>
#include <vector>
#include <string>
using namespace std;
class MenuItem {
public:
    string name;
    string type; 
    double price;
    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};
class CoffeeShop {
private:
    string shopName;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string name) : shopName(name) {}
    void addMenuItem(const MenuItem& item) {
        menu.push_back(item);
    }
    
    string addOrder(string itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() const {
        return orders;
    }

    double dueAmount() const {
        double total = 0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }

    string cheapestItem() const {
        if (menu.empty()) return "Menu is empty";
        const MenuItem* cheapest = &menu[0];
        for (const auto& item : menu) {
            if (item.price < cheapest->price) {
                cheapest = &item;
            }
        }
        return cheapest->name;
    }

    vector<string> drinksOnly() const {
        vector<string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() const {
        vector<string> foods;
        for (const auto& item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main() {
    CoffeeShop shop("Java Cafe");
    shop.addMenuItem(MenuItem("Cappuccino", "drink", 4.50));
    shop.addMenuItem(MenuItem("Latte", "drink", 4.00));
    shop.addMenuItem(MenuItem("Espresso", "drink", 3.00));
    shop.addMenuItem(MenuItem("Muffin", "food", 2.50));
    shop.addMenuItem(MenuItem("Sandwich", "food", 5.00));
    cout << shop.addOrder("Cappuccino") << endl;
    cout << shop.addOrder("Muffin") << endl;
    cout << shop.addOrder("Browniw") << endl;  
    vector<string> orders = shop.listOrders();
    cout << "Orders taken: ";
    for (const auto& order : orders) cout << order << ", ";
    cout << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl; 
    cout << "Total due: $" << shop.dueAmount() << endl;
    cout << "Cheapest item: " << shop.cheapestItem() << endl;
    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks available: ";
    for (const auto& drink : drinks) cout << drink << ", ";
    cout << endl;
    vector<string> foods = shop.foodOnly();
    cout << "Food available: ";
    for (const auto& food : foods) cout << food << ", ";
    cout << endl;
    return 0;
}

