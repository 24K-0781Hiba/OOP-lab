#include <iostream>
#include <thread> //for this_thread::sleep_for
#include <chrono> //for chrono::seconds

using namespace std;

class Grind {
public:
    void grindJuice() {
        cout << "Grinding fruits... Please wait." << endl;
        this_thread::sleep_for(chrono::seconds(5)); //to ive grinding for 5 secs
        cout << "Grinding complete!" << endl;
    }
};

class Blend {
public:
    void blendJuice() {
        cout << "Blending fruits... Please wait." << endl;
        for (int i = 0; i < 5; ++i) { //go show blending for 5 seconds
            this_thread::sleep_for(chrono::seconds(1)); //sleep for 1 second x 5 
            cout << "Blending in progress... (" << i + 1 << " seconds)" << endl;
        }
        cout << "Blending complete!" << endl;
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void makeJuice() {
        cout << "Starting juice making process..." << endl;
        blender.blendJuice();
        grinder.grindJuice(); 
        cout << "Juice is ready! Enjoy!" << endl;
    }
};

int main() {
    JuiceMaker juiceMaker;
    juiceMaker.makeJuice();
    return 0;
}
