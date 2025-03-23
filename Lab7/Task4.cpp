#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    string id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, string i, string addr, string phone, string e)
        : name(n), id(i), address(addr), phoneNumber(phone), email(e) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    virtual void updateInfo(string n, string addr, string phone, string e) {
        name = n;
        address = addr;
        phoneNumber = phone;
        email = e;
    }
};

class Student : public Person {
private:
    vector<string> coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, string i, string addr, string phone, string e, double gpa, int year)
        : Person(n, i, addr, phone, e), GPA(gpa), enrollmentYear(year) {}

    void enrollCourse(const string& course) {
        coursesEnrolled.push_back(course);
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "Courses Enrolled: ";
        for (const string& course : coursesEnrolled) {
            cout << course << " ";
        }
        cout << endl;
    }
};

class Professor : public Person {
private:
    string department;
    vector<string> coursesTaught;
    double salary;

public:
    Professor(string n, string i, string addr, string phone, string e, string dept, double sal)
        : Person(n, i, addr, phone, e), department(dept), salary(sal) {}

    void assignCourse(const string& course) {
        coursesTaught.push_back(course);
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
        cout << "Courses Taught: ";
        for (const string& course : coursesTaught) {
            cout << course << " ";
        }
        cout << endl;
    }
};

class Staff : public Person {
private:
    string department;
    string position;
    double salary;

public:
    Staff(string n, string i, string addr, string phone, string e, string dept, string pos, double sal)
        : Person(n, i, addr, phone, e), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Course {
private:
    string courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;

public:
    Course(string id, string name, int cred, string instr, string sched)
        : courseId(id), courseName(name), credits(cred), instructor(instr), schedule(sched) {}

    void registerStudent(Student& student) {
        student.enrollCourse(courseName);
    }

    void displayCourseInfo() const {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
    }
};

int main() {

    Student student("Muhammad Ali", "S12345", "123 Faisal Town", "555-1234", "ali.khan@nu.edu.pk", 3.8, 2021);
    Professor professor("Dr. Sana Ahmed", "P67890", "456 Gulberg", "555-5678", "sana.ahmed@nu.edu.pk", "Computer Science", 75000);
    Staff staff("Bilal Hassan", "E13579", "789 Model Town", "555-9876", "bilal.hassan@nu.edu.pk", "HR", "Manager", 50000);
    Course course("CS101", "Introduction to Computer Science", 3, "Dr. Sana Ahmed", "Mon/Wed 10:00 AM");
    course.registerStudent(student);
    student.displayInfo();
    cout << "-------------------------" << endl;
    professor.displayInfo();
    cout << "-------------------------" << endl;
    staff.displayInfo();
    cout << "-------------------------" << endl;
    course.displayCourseInfo();

    return 0;
}
