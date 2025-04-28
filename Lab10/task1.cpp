#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string encryption(const string& txt){
    string encrypted= txt;
    for (size_t i=0; i<encrypted.length(); i++){
        encrypted[i] = encrypted[i] + static_cast<char>(i+1);
    }
    return encrypted;
}
int main(){
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    string encrypted = encryption(str);
    ofstream file("Task1.txt");
    if (file.is_open()){
        file << encrypted;
        file.close();
        cout << "Normal text: "<<str<<endl;
        cout << "Encrypted text in file: "<<encrypted<<endl;
    } else {
        cerr << "Error opening file";
        return 1;
    }

    
}
