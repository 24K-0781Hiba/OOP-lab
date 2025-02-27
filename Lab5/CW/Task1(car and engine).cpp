#include<iostream>
using namespace std;

class Engine{
	bool isRunning;
	public:
		Engine(){
			cout<<"Engine created.\n";
		}
		~Engine(){
			cout<<"Engine destroyed.\n";
		}
		void start(){
			cout<<"\nEngine started\n";
			isRunning = true;
		}
		void stop(){
			cout<<"\nEngine stopped\n";
			isRunning= false;
		}
};

class Car{
	Engine engine;
	public:
		Car() {
            cout<<"Car created.\n";
        }
        ~Car() {
            cout <<"\nCar destroyed.\n";
        }
		void startCar(){
			cout<<"\nStarting the car";
			engine.start();
		}
		void stopCar(){
			cout<<"\nStopping the car";
			engine.stop();
		}
};

int main(){
	Car car;
	car.startCar();
	car.stopCar();
	cout<<"\nEngine was created when car was created. Car obj has been destroyed. so is the enine object\n";
	return 0;
}
