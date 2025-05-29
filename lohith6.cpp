#include<iostream>
using namespace std;

class math{
public:
    int multiply(int a, int b ) {
        return a * b;
    }
    float multiply(float a,float b) {
        return a * b;
    }
    int multiply(float a,float b,float c) {
        return a * b * c;
    }    
};

int main() {
    math m;
    cout << m.multiply(2, 3) <<endl;
    cout << m.multiply(2.5f, 3.5f) <<endl;
    cout << m.multiply(2, 3, 5) <<endl;
}