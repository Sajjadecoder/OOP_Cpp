#include<iostream>
#include<string>
using namespace std;
class student{
    int age;
    string name;
    public:
    student(){}
    student(string name,int age):name(name),age(age) {}
    bool operator!=(student &obj){
        if (this->age!=obj.age || this->name != obj.name)
        {
            return true;
        }return false;
        
    }
    
};


int  main(){
    student s1("sajjad",10);
    student s2("sajjad",110);
    bool notSame = s1!=s2;
    cout<<notSame;
    return 0;
}