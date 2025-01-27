#include<iostream>
using namespace std;

int main(){
	int units;
	float bill=0, surcharge=0;
	string name, id;
	cout <<"Enter customer ID: ";
	getline(cin, id);
	cout <<"Enter customer name: ";
	getline(cin, name);
	cout <<"Enter units consumed: ";
	cin>>units;
	if (units<0){
		cout<<"Invalid units entered";
		return 0;
	}
	cout<<"Customer ID: "<<id;
	cout<<"\nCustomer name: "<<name;
	cout<<"\nUnits consumed: "<<units;
	if (units<=199){
		bill = units * 16.20;
		cout<<"\nAmount charges @Rs 16.20 per unit: "<<bill;
	} else if (units>=200&&units<300){
		bill = units * 20.10;
		cout<<"\nAmount charges @Rs 20.10 per unit: "<<bill;
	} else if (units>=300&&units<500){
		bill = units * 27.10;
		cout<<"\nAmount charges @Rs 27.10 per unit: "<<bill;
	} else if (units>=500){
		bill = units * 35.90;
		cout<<"\nAmount charges @Rs 35.90 per unit: "<<bill;
	}
	if (bill>18000){
		surcharge =bill*0.15;
		bill = bill+surcharge;
	}
	cout<<"\nSurcharge amount: "<<surcharge;
	cout<<"\nNet amount paid by customer: "<<bill;
	return 0;
}
