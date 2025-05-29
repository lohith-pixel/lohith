#include<iostream>
using namespace std;

int main()
{
    string food = "pizza";
    string *food_address = &food;

    cout << "value of food: " << food << endl;
    cout << "address of food: " << food_address << endl;
    
    *food_address = "biriyani";
    cout << "value of food: " << food << endl;
    cout << "address of food: " << food_address << endl;
}




