#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// Class to represent an Employee Record
class Employee {
public:
    int id;
    string name;
    string designation;
    int years_of_service;

    Employee(int id, string name, string designation, int years_of_service)
        : id(id), name(name), designation(designation), years_of_service(years_of_service) {}

    // Method to print the employee record
    void print() {
        cout << id << ", " << name << ", " << designation << ", " << years_of_service << endl;
    }

    // Method to serialize employee to CSV string
    string toCSV() {
        stringstream ss;
        ss << id << "," << name << "," << designation << "," << years_of_service;
        return ss.str();
    }

    // Static method to deserialize CSV string to Employee object
    static Employee fromCSV(const string &csv) {
        stringstream ss(csv);
        string token;
        int id, years_of_service;
        string name, designation;

        getline(ss, token, ',');
        id = stoi(token);
        getline(ss, name, ',');
        getline(ss, designation, ',');
        getline(ss, token, ',');
        years_of_service = stoi(token);

        return Employee(id, name, designation, years_of_service);
    }
};

// Function to load all employees from a file
vector<Employee> loadEmployeesFromFile(const string& filename) {
    ifstream file(filename);
    vector<Employee> employees;
    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            employees.push_back(Employee::fromCSV(line));
        }
    }

    file.close();
    return employees;
}

// Function to save all employees back to the file
void saveEmployeesToFile(const string& filename, const vector<Employee>& employees) {
    ofstream file(filename);
    for (const auto& emp : employees) {
        file << emp.toCSV() << endl;
    }
    file.close();
}

// Function to find managers with at least 2 years of service
vector<Employee> findManagersWithMinYears(const vector<Employee>& employees, int min_years) {
    vector<Employee> result;
    for (const auto& emp : employees) {
        if (emp.designation == "Manager" && emp.years_of_service >= min_years) {
            result.push_back(emp);
        }
    }
    return result;
}

// Function to delete all employees except the given ones
void deleteEmployeesExcept(vector<Employee>& employees, const vector<Employee>& toKeep) {
    vector<Employee> newEmployees;
    for (const auto& emp : toKeep) {
        newEmployees.push_back(emp);
    }
    employees = newEmployees;
}

void updateEmployeeData(vector<Employee>& employees) {
    for (auto& emp : employees) {
        emp.id += 1;  // Increment ID
        emp.years_of_service += 1;  // Increment years of service
    }
}

int main() {
    string filename = "employees.txt";
    vector<Employee> employees = loadEmployeesFromFile(filename);
    vector<Employee> managers = findManagersWithMinYears(employees, 2);

    cout << "Managers with at least 2 years of service:" << endl;
    for (const auto& manager : managers) {
        manager.print();
    }

    deleteEmployeesExcept(employees, managers);
    cout << "\nData after deletion (only managers with at least 2 years of service):" << endl;
    for (const auto& emp : employees) {
        emp.print();
    }

    updateEmployeeData(managers);
    cout << "\nData after incrementing ID and years of service:" << endl;
    for (const auto& emp : managers) {
        emp.print();
    }

    saveEmployeesToFile(filename, managers);

    return 0;
}
