#include <iostream>
#include <string>
#define nl cout<<endl;
using namespace std;
class loc
{
public:
    int num1, num2;
    loc() {}
    loc(int n1, int n2) : num1(n1), num2(n2) {}
    loc* operator+=(int num)
    {
        this->num1 += num;
        this->num2 += num;
        return this;
    }//obj1+=20
    loc operator+(int num){
        loc temp = *this;
        temp.num1 += num;
        temp.num2 += num;
        return temp;
    }//loc obj3 = obj2+10;
};

int main()
{
    loc obj1(10,10);
    obj1+=20;
    cout<<obj1.num1<<" "<<obj1.num2;nl;
    loc obj2(50,50);
    loc obj3 = obj2+10;
    cout<<obj3.num1<<" "<<obj3.num2;nl;
    return 0;
}