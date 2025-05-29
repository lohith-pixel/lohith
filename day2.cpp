#include <iostream>
using namespace std;
class person 
{
    public:
    string name;
    int age;
    person(int person_age,string person_name )
    {
        name = person_name;
        age = person_age;
    }
        void intro()
        {
            cout << "my name is " << name <<endl
                 <<"my name is " <<age <<endl;
        }
};
int main () 
{
    person p1(27,"Darani goutam");
    person p2(2,"keethana Darani ");
    p1.intro();
    p2.intro();
} 