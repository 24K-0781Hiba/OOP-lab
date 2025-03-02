#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CoffeeShop {
public:
    const string Name; 
    vector<pair<string, double>> Menu; 
    vector<string> orders; 

    CoffeeShop(const string& name, const vector<pair<string, double>>& menu)
        : Name(name), Menu(menu) {}

    string addOrder(const string& item_name) {
        for (const auto& item : Menu) {
            if (item.first == item_name) {
                orders.push_back(item_name);
                return "Added " + item_name + " to orders!";
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready!";
        } else {
            return "All orders have been fulfilled!";
        }
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0.0;
        for (const auto& item_name : orders) {
            for (const auto& item : Menu) {
                if (item.first == item_name) {
                    total += item.second;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (Menu.empty()) return "";
        auto cheapest = min_element(Menu.begin(), Menu.end(),
            [](const pair<string, double>& a, const pair<string, double>& b) {
                return a.second < b.second;
            });
        return cheapest->first;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto& item : Menu) {
            if (item.first.find("drink") != string::npos) {
                drinks.push_back(item.first);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (const auto& item : Menu) {
            if (item.first.find("food") != string::npos) {
                food.push_back(item.first);
            }
        }
        return food;
    }
};

int main() {
    vector<pair<string, double>> menu = {
        {"espresso drink", 2.5},
        {"cappuccino drink", 3.0},
        {"sandwich food", 5.0},
        {"croissant food", 4.0}
    };

    CoffeeShop shop("Java Junction", menu);

    cout << shop.addOrder("espresso drink") << endl;
    cout << shop.addOrder("sandwich food") << endl;
    cout << shop.addOrder("latte drink") << endl; //

    cout << "Orders: ";
    for (const auto& order : shop.listOrders()) {
        cout << order << " ";
    }
    cout << endl;

    cout << "Total due amount: $" << shop.dueAmount() << endl;

    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    cout << "Drinks: ";
    for (const auto& drink : shop.drinksOnly()) {
        cout << drink << " ";
    }
    cout << endl;

    cout << "Food: ";
    for (const auto& food : shop.foodOnly()) {
        cout << food << " ";
    }
    cout << endl;

    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;

    return 0;
}
