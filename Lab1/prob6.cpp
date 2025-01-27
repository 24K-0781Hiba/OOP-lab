#include<iostream>
using namespace std;

int main(){
	string name;
	float scores[5], avg=0;
	int i;
	cout<<"Enter student's name: ";
	getline(cin, name);
	for (i=0; i<5; i++){
		cout << "Enter score "<<i+1<<": ";
		cin>>scores[i];
		avg += scores[i];
	}
	avg /= 5;
	cout<<"Student name: "<<name<<endl;
	for (i=0; i<5; i++){
		cout<<scores[i];
		if (i!=4){
			cout<<", ";
		}
	}
	cout<<"\nAvergae test score: "<<avg;
	return 0;
}
