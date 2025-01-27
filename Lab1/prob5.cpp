#include<iostream>
using namespace std;

int main(){
	string name;
	float adult, child; //ticketprice
	int cTickets, aTickets, totTickets; //number of tickets
	float perdonate;
	float gross, donation, netsale;
	cout << "Enter movie name: ";
	getline(cin, name);
	cout << "Enter adult ticket price: ";
	cin>>adult;
	cout << "Enter child ticket price: ";
	cin>>child;
	cout << "Enter adult tickets sold: ";
	cin>>aTickets;
	cout << "Enter child tickets sold: ";
	cin>>cTickets;
	cout <<"Enter percentage to be donated: ";
	cin >> perdonate;
	totTickets = aTickets + cTickets;
	gross = (aTickets*adult) + (cTickets*child);
	donation = (perdonate/100) * gross;
	netsale = gross - donation;
	cout << "Movie name: "<<name;
	cout <<"\nNumber of tickes sold: "<<totTickets;
	cout << "\nGross amount: $"<<gross;
	cout << "\nPercentage of gross amount donated: "<<perdonate<<"%";
	cout << "\nAmount donated: $"<<donation;
	cout << "\nNet sale: $"<<netsale;
}
