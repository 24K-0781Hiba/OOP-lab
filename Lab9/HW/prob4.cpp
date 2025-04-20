#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
public:
    virtual float getTuition(string status, int creditHours) = 0;

    void setName(string n) {name = n;}

    string getName() const { return name;}
};

// Derived class GraduateStudent
class GraduateStudent : public Student {
private:
    string researchTopic;
public:
    void setResearchTopic(string topic) {researchTopic = topic;}

    string getResearchTopic() const {return researchTopic;}

    float getTuition(string status, int creditHours) override {
        int rate;
        if (status == "undergraduate")
            rate = 200;
        else if (status == "graduate")
            rate = 300;
        else if (status == "doctoral")
            rate = 400;
        else {
            cout << "Invalid status." << endl;
            return 0;
        }
        return rate * creditHours;
    }
};

int main() {
    GraduateStudent gs;
    string name, topic, status;
    int creditHours;
    cout << "Enter student name: ";
    getline(cin, name);
    gs.setName(name);
    cout << "Enter research topic: ";
    getline(cin, topic);
    gs.setResearchTopic(topic);
    cout << "Enter status (undergraduate/graduate/doctoral): ";
    cin >> status;
    cout << "Enter credit hours: ";
    cin >> creditHours;
    cout << "\nStudent Name: " << gs.getName() << endl;
    cout << "Research Topic: " << gs.getResearchTopic() << endl;
    cout << "Tuition Fee: $" << gs.getTuition(status, creditHours) << endl;

    return 0;
}
