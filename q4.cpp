 #include<iostream>
 #include<string>
using namespace std;
// class A{
//     int x;
//     public:
//     A(){cout<<"Default constructor of A\n";}
//     A(int x):x(x){cout<<"Parameterized constructor of A\n";}


// };
// class B{
//     A a;
//     int y;
//     public:
//     B(){cout<<"Default constructor of B\n";}
//     B(int x):y(x) {cout<<"Parameterized constructor of B\n";}
// };
// int main(){
//     B obj;
//     return 0;
// }
class A{
    public:
    A(){}
    int x = 10;
};
class B:public A{
    public:
    B(){}
    int x = 20;
};

class C{
    protected:
    int x;
    public:
    C(){}
    virtual void dis(){cout<<"X";}
};
class D:public C{
    int y;
    public:
    D(){}
    void dis(){cout<<"Y";}
};
int main(){
    A *ptr;
    B b;
    ptr = &b;
    cout<<ptr->x;
    //output: 10
    cout<<endl<<endl;
    C *obj;
    D o2;
    obj = &o2;
    obj->dis();
}
