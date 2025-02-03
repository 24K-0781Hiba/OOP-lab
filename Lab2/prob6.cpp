#include <iostream>
#include <vector>
using namespace std;
struct Subject {
    string subjectName;
};
struct Student {
    int id;
    vector<Subject> subjects; 
};

int main() {
    int n;
    cout<<"Enter number of students: ";
    cin >>n;
    vector<Student> students(n);
    for (int i =0; i<n; i++) {
        cout<< "Enter Student ID: ";
        cin >>students[i].id;
        int subjectCount;
        cout <<"Enter number of subjects for Student " << students[i].id << ": ";
        cin>>subjectCount;
        students[i].subjects.resize(subjectCount);
        for (int j=0; j<subjectCount; j++) {
            cout<< "Enter subject "<< j+1<< ": ";
            cin>>students[i].subjects[j].subjectName;
        }
    }
    cout <<"\nStudent Details:\n";
    for (const auto& student : students) {
        cout <<"ID: "<<student.id <<"\nSubjects: ";
        for (const auto& subj : student.subjects) {
            cout<<subj.subjectName << " ";
        }
        cout <<endl;
    }
    return 0;
}

