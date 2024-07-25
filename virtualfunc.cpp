#include <iostream>
#include <string>
using namespace std;
class baseclass
{
public:
    baseclass() {}
    int a = 10;
    virtual void display()
    {
        cout << "Baseclass display " << a << endl;
    }
};
class derivedclass : public baseclass
{
public:
    derivedclass() {}
    int b = 5;
    void display()
    {
        cout << "derivedCLass display " << a << " " << b << endl;
    }
};

int main()
{
    // run time polymorphism also called late binding
    baseclass *ptr;
    derivedclass obj;
    ptr = &obj;
    ptr->display();
    cout << endl
         << endl; // virtual func ki wja se derived class ka display() call hoga (achieving runtime polymorphism) and base class ka display() call nai hoga
    delete ptr;
    derivedclass *ptr2;
    ptr2 = &obj;
    ptr2->display(); // derived class ka display() call hoga
    delete ptr2;
    return 0;
    derivedclass pp;
    pp.display(); // this wont run as compiler doesnt know which display func should be called
    // virtual funcs ko pointer k through call kia jaata hai tou wou derived classes ka func call krte hain. Apni baseclass ka NAI!
    // virtual funcs in base class are never called by the compiler if we try to call them using pointers(above ptr example)
    // agr derived class mei same name(eg. display()in the above code) ka func nai hai tou it'll automatically call base class ka function
}