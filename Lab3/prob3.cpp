#include <iostream>
#include <cstdlib>  
using namespace std;
class Glass {
public:
    int liquidLevel= 200;
    void Drink(int milliliters) {
        liquidLevel -= milliliters;  

        if (liquidLevel<100) {  
            Refill();
        }
    }
    void Refill() {
        liquidLevel =200;
        cout<< "Glass refilled to 200.\n";
    }
};

int main(int argc, char* argv[]) {
    if (argc<2) {
        cout<< "Usage: "<<argv[0]<<" <amount1> <amount2> ...\n";
        return 1;
    }
    Glass glass;
    for (int i=1; i<argc; i++) {
        int level = atoi(argv[i]);  
        if (level <= 0) { 
            cout<<"Invalid input: "<<argv[i] <<"\n";
            continue;
        }
        glass.Drink(level);
        cout <<"Current liquid level: "<<glass.liquidLevel<< " ml\n";
    }
    return 0;
}
