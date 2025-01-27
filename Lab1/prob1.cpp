#include<iostream>
using namespace std;
int main(){
	int a[5], i;
	for (i=0; i<5; i++){
		cout << "Enter number "<<i+1<<": ";
		cin >> a[i];
	}
	int *max1 = 0, *max2 = 0;
	for (i=0; i<5; i++){
		if (!max1 ||  a[i]>*max1){
			max2=max1;
			max1=&a[i];
			
		} else if ((!max2 || a[i]>*max2)&&a[i] != *max1){
			max2 = &a[i];
		}
	}
	if (max2){
		cout << "Second largest no in the array: "<<*max2<<endl;
	} else {
		cout << "No second largest umber found :(";
	}
	return 0;
}
