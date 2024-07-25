#include<iostream>
#include<string>
using namespace std;
template<class T>
class User{
    protected:
    string name;
    int age;
    public:
    User(){}
    User(string s,int a):name(s),age(a) {}
    virtual void display()=0;

};
class Student:public User<Student>{
    string rollnum;
    public:
    Student(){}
    Student(string roll,string n,int a):User<Student>(n,a),rollnum(roll) {}
    void display(){
        cout<<rollnum<<" "<<name<<" "<<age<<endl;
    }
};
class Teacher:public User<Teacher>{
    string course;
    public:
    Teacher(){}
    Teacher(string c,string n,int a):User<Teacher>(n,a),course(c) {}
    void display(){
        cout<<course<<" "<<name<<" "<<age<<endl;
    }
};
int main(){
    User<Teacher>* t;
    Teacher obj("oop","yasir",32);
    t = &obj;
    t->display();
    return 0;
}