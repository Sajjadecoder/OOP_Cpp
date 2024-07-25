#include<iostream>
using namespace std;
class hero{
    int *age;
    string *name;
    public:
        hero(){
            age = new int;
            name = new string;
        }
        hero(const hero& myHero){
            
            age=new int(*myHero.age);
            name = new string (*myHero.name);
        }
        int getage(){return *age;}
        string getName(){return *name;}
        void setn(string n){
            *name =n;
        }
        void disp(){

            cout<<"name: "<<*name<<endl;
            cout<<"Age: "<<*age<<endl<<endl;
        }
        void seta(int a){
            *age=a;
        }
    
};
int main(){
    hero obj1;
    obj1.seta(10);
    obj1.setn("sajjad");
    hero obj2(obj1);
    obj2.disp();
    obj1.disp();
    cout<<"-----\n";
    obj2.seta(19);
    obj2.setn("ahmed");
    obj1.disp();
    obj2.disp();

}