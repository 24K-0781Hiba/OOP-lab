#include <iostream>
#include <vector>
#include <algorithm>  //I hope it's okay to use this
using namespace std;
struct Person {
    int id;
    string name;
};
bool compareById(const Person& a, const Person& b) {
    return a.id < b.id;
}
bool compareByName(const Person& a, const Person& b) {
    return a.name < b.name;
}
int main() {
    int n;
    cout << "Enter number of persons: ";
    cin >>n;
    vector<Person> persons(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter ID and Name for person " << i + 1 << ": ";
        cin >> persons[i].id >> persons[i].name;
    }
    sort(persons.begin(), persons.end(), compareById);
    cout << "\nSorted by ID:\n";
    for (const auto& p : persons) {
        cout<< "ID: " << p.id << ", Name: " << p.name << endl;
    }
    sort(persons.begin(), persons.end(), compareByName);
    cout <<"\nSorted by Name:\n";
    for (const auto& p : persons) {
        cout<< "ID: " << p.id << ", Name: " << p.name << endl;
    }
    return 0;
}

