#include<iostream>
#include<string>
using namespace std;
class base{
    protected:
    int data;
    public:
    base(){
        cout<<"Base default constructor called\n";
    }
    base(int x){
        cout<<x<<" base parameterized constructor called\n";
        data = x;
    }
    ~base(){
        cout<<"Base destructor called\n";
    }

};
class derived:public base{
    
    public:
    derived(){
        cout<<"derived default constructor called\n";
    }
    derived(int x): base(x){
        cout<<x<<" derived parameterized constructor called\n";
        
    }
    ~derived(){
        cout<<"derived destructor called: "<<data<<endl;
    }
    derived operator + (derived &obj){
        derived temp = *(this);

        temp.data+=obj.data; 
        return temp;
    }
};

int main(){
    derived obj1 = derived(10);
    cout<<endl<<endl;
    derived obj2= derived(20);
    cout<<endl<<endl;
    derived result = obj1+obj2;
    base *ptr = new base(90);
    return 0;
}