#include<iostream>
#include<string>
using namespace std;
class A{
    int x;
    public:
    A(){cout<<"A constructor\n";}
    virtual void dis(){
        cout<<"X\n";
    }
    ~A(){cout<<"A destructor\n";}
};
class B: public A{
    public:
    B(){cout<<"B constructor\n";}
    void dis(){
        cout<<"Y\n";
    }
    ~B(){cout<<"B destructor\n";}
};
int main(){
    B obj,*ptr;
    obj.dis();//Y
    A obj2;
    obj2.dis();//X
    ptr = new B();
    ptr->dis();//Y
} 