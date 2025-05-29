#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ofstream file("example.txt");
    file << "hello, c++ file!";
    file.close();
    cout<<"file written successfully." << endl;
    return 0;
}