#include<iostream>
using namespace std;

int main(){
	int n, i, sum=0;
	cout <<"Number of elements: ";
	cin >> n;
	int *a = new int[n];
	for (i=0; i<n; i++){
		cout <<"enter element "<< i+1<<": ";
		cin >> a[i];
	}
	for (i=0; i<n; i++){
		sum += *(a + i);
	}
	cout << "Sum: "<<sum;
	delete[] a;
	return 0;
}
