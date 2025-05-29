#include<iostream>
using namespace std;
{
    public:
        string name;
        char gender;
        int age;

};

class student: public Person
{
        public:
        string college;
        string department;
};

class teacher : public person
{
    public:
        string college;
        int salary;
        string designation;
};

int main()
{
        student s1;
        teacher t1;
        s1.name="virat";
        s1.age=19;
        s1.college="city engineering";
        s1.department="ECE";
        s1.gender="Male";
        t1.college="city engineering";
        t1.designation="Lecturer";
        t1.salary=80000;
        cout<<"student name is "<<s1.name<<endl;
        cout<<"student age is "<<s1.age<<endl;
        cout<<"student college is "<<s1.college<<endl;
        cout<<"student department is "<<s1.department<<endl;
        cout<<"student gender is "<<s1.gender<<endl;
        cout<<"teacher college is "<<t1.college<<endl;
        cout<<"teacher designation is "<<t1.designation<<endl;
        cout<<"teacher salary is "<<t1.salary<<endl;

}



