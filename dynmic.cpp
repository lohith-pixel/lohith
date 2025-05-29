#include<iostream>
#include<vector>
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
        cout<<"==============="<<endl;

    }
};

int main()
{
   string name,pancard,aadharcard;
   vector<Person>list_of_user;
   for(int i=0;i<3;i++)
   {
    cout<<"Enter the name for"<<i+1<<":"<<endl;
    cin>>name;
    cout<<"Enter the pancard"<<i+1<<":"<<endl;
    cin>>pancard;
    cout<<"Enter the aadharcard"<<i+1<<":"<<endl;
    cin>>aadharcard;
    list_of_user.push_back(Person(name,pancard,aadharcard));
   }
    for(Person user:list_of_user)
    {
        user.display_details();
    }
 
}
