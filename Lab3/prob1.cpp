#include<iostream>
using namespace std;
class User{
	public:
		int age;
		string name;
};

int main(){
	User Person;
	Person.name = "Teo";
	Person.age = 24;
	cout << "My name is "<<Person.name<<" and I'm "<<Person.age<<" Years old.";
	return 0;
}
  