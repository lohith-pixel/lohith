#include<iostream>
using namespace std;

class Person
{
public:
    string name;
    string pancard_number;
    string aadhar_card_number;

    Person(string user_name,string p_card,string a_card)
    {
        name=user_name;
        pancard_number=p_card;
        aadhar_card_number=a_card;
    }
    void display_details()
    {
        cout<<"user details"<<endl;
        cout<<"user name"<<name<<endl;
        cout<<"Pancard"<<pancard_number<<endl;
        cout<<"Aadharcard"<<aadhar_card_number<<endl;


    }
}:
int main()
{
    vector<Person>list of user;
    list_of_user.push_back(Person("john","SSR123RF","PP77775"));
    list_of_user.push_back(Person("john","SPR123RF","PPR3775"));
    list_of_user.push_back(Person("virat","MNP23RF","PP55555"));

    for(Person user:list_of_user)
    {
        user.display_details();
    }
 
}
