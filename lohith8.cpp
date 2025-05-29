#include<iostream>
using namespace std;

class point {
public:
    int x,y;
    
    point(int a, int b) {
        x = a;
        y = b;
    }

    point operator-(point p) {
        return point(x-p.x, y-p.y);
    }
    void show() {
        cout << x <<","<<y << endl;
    }     
};

int main() {
    point P1(1, 2);
    point P2(2, 3);
    point P3 = P1-P2;
    P3.show();
}