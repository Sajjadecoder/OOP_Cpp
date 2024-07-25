#include<iostream>
#include<string>
using namespace std;
class A{
    int val;
    public:
    A(){}
    A(int x):val(x) {}
    bool operator!=(A &obj);
};
bool A::operator!=(A &obj){
    return !(this->val == obj.val);
}
int main(){
    A obj1(5);
    A obj2(10);
    bool res = obj1!=obj2;
    cout<<res;
    return 0;
}