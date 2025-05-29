#include<iostream>
using namespace std;

class book{
public:
        string title;
        string author;
        float price;
    book(){
        title="  unknown  ";
        author="  unknown  ";
        price=  1234;

    }
    void display(){
        cout<<"Title"<<title<<"Author"<<author<<"Price"<<price<<endl;
    }
};

int main()
{
    book b;
    b.display();
    return 0;
}