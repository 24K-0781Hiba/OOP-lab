#include <iostream>
using namespace std;
class Employee {
public:
    string firstName;
    string lastName;
    double monthlySalary;
    Employee(string fName, string lName, double salary) {
        firstName = fName;
        lastName = lName;
        monthlySalary = (salary>0)? salary : 0.0; 
    }
    double getYearlySalary() { 
        return monthlySalary*12; 
    }
    void raiseSalary(double percentage) {
        if (percentage>0)
            monthlySalary+= (monthlySalary*percentage/100);
    }
};
int main() {
    Employee emp1("Erwin", "Reiss", 3000);
    Employee emp2("Jonathan", "Smith", -2000); 
    cout<<emp1.firstName<< " "<< emp1.lastName << " Yearly Salary: $\n"<< emp1.getYearlySalary();
    cout<<emp2.firstName<<" " <<emp2.lastName<<" Yearly Salary: $\n" << emp2.getYearlySalary();
    emp1.raiseSalary(10);
    emp2.raiseSalary(10);
    cout<<"\nAfter 10% raise:\n";
    cout<<emp1.firstName<<" "<<emp1.lastName <<" Yearly Salary: $\n" << emp1.getYearlySalary();
    cout<<emp2.firstName<<" "<< emp2.lastName<< " Yearly Salary: $\n" << emp2.getYearlySalary();
    return 0;
}

