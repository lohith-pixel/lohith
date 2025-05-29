#include<iostream>
using namespace std;
class person
{
    public:
    string name;
    int age;
};
int main()
{
    person p1;
    p1.name="raj";
    p1.age=20;

    person p2;
    p2.name="kumar";
    p2.age=23;
    cout<<p1.name<<endl<<p1.age<<endl;
    cout<<p2.name<<endl<<p2.age<<endl;
}