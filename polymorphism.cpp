#include <iostream>
#include <string>
using namespace std;
class baseclass
{
public:
    baseclass() {}
    int a=10;
    void display()
    {
        cout << "Baseclass display "<<a<<endl;
    }
};
class derivedclass : public baseclass
{
public:
    derivedclass() {}
    int b=5;
    void display()
    {
        cout << "derivedCLass display "<<a<<" "<<b<<endl;
    }
};

int main()
{
    // compile time polymorphism also called early binding
    baseclass *ptr;
    derivedclass obj;
    ptr = &obj;
    ptr->display();cout<<endl<<endl;//sirf baseclass ka display() call hoga (achieving compile time polymorphism)
    delete ptr;
    derivedclass *ptr2;
    ptr2 = &obj;
    ptr2-> display();//derived class ka display() call hoga
    delete ptr2;
    return 0;
}