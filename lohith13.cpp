#include<iostream>
using namespace std;

int main()
{
    int *num = new int;
    *num = 50;
    cout << "allocated value: " << *num << endl;
    cout << "size of the variable: " << sizeof(*num)<<endl;
}