#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("number.txt");
    int num, sum = 0;

    while (file >> num) {
        sum += num;
    }

    cout << "sum: " << sum << endl;
    file.close();
    return 0;
}