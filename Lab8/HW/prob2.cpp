#include<iostream>
#include<string>
using namespace std;

class Shape{
    double area;
    public:
    Shape (double a):area(a){}

    Shape operator +(Shape& s2){
        return Shape (area + s2.area); 
    }
    double getArea(){ return area;}
    void display(){
        cout << "Area: " << getArea() <<" square units";
    }
};

int main(){
    Shape s1(20);
    Shape s2(23);
    Shape s3 = s1 + s2;
    s3.display();
    return 0;
}
