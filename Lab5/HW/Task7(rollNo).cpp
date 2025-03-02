#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    const string roll_no;
public:
    Student(const string& roll) : roll_no(roll) {}
    void display() const {
        cout << "Student Roll Number: " << roll_no << endl;
    }
};

int main() {
    string rollNumber;
    cout << "Enter the student's roll number: ";
    getline(cin, rollNumber);
    Student student(rollNumber);
    student.display();
    return 0;
}
