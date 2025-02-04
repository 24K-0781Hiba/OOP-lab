#include<iostream>
using namespace std;
class Date{
	public:
		int day;
		int month;
		int year;
		void displayDate(){
			cout<<day<<"/"<<month<<"/"<<year;
		}
};

int main(){
	Date today;
	today.day = 4;
	today.month = 2;
	today.year = 2025;
	today.displayDate();
	return 0;
}