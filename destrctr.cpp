#include<iostream>
using namespace std;

class person
{
public:
    string name;
    person(string user_name)
    {
        name=user_name;
        cout<<"Object created"<<name<<endl;
    }
    ~person()
    {
        cout<<"Object destructed"<<name<<endl;
    }
};

int main()
{
    person P1("virat");
    person P2("kohli");
    return 0;
}