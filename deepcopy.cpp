#include<iostream>
#include<string>
using namespace std;
class base{
  int x,y;
  public:
  int *ptr;
  base(){ ptr  = new int;}
  base(int x,int y,int val):x(x),y(y) {
    ptr  = new int;
    *ptr = val;
  }
  base(base &obj){
    obj.x = this -> x;
    obj.y = this -> y;
    *(obj.ptr) = *ptr;
  }
  void dis(){
    cout<<"X: "<<x<<endl;
    cout<<"Y: "<<y<<endl;
    cout<<"ptr: "<<*ptr<<endl;
    cout<<endl;
  }
};


int main(){
    base obj1;
    base obj2(10,20,50);
    obj1=(obj2);
    obj1.dis();
    *(obj1.ptr) = 8;
    obj2.dis();
}