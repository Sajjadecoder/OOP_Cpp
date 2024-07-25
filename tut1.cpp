#include<iostream>
using namespace std;
class Hero
{
    int health;
    string name;
    public:
    Hero(int h,string name){
        this->health = h;
        this->name = name;
    }
    int getHealth(){
        return health;

    }
    void getName(){
        cout<<name;
    }
};

int main(){
    string name;int health;
    cout<<"Enter name: ";cin>>name;
    cout<<"Enter health: ";cin>>health;
    Hero Sajjad(health,name);
    cout<<"Health is: "<<Sajjad.getHealth()<<endl;
    cout<<"Name is: ";
    Sajjad.getName();



}