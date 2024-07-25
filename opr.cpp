#include<iostream>
#include<string>
#define nl endl
using namespace std;
class User{
    int x,y;
    public:
    User(){
        x=0;y=0;
    }
    int operator ++ (int){
        this->x++;
        this->y++;
    }
    void display(){
        cout<<"x: "<<x<<nl<<"y "<<y<<nl<<nl;

    }
    User operator ++(){
        User temp = *(this);
        temp.x++;
        temp.y++;
        return temp;
    }
    User operator +=(int num){
        this->x+=num;
        this->y+=num;
        return *(this);
    }
};

int main(){
    User user1;
    User user2;
    user1++;
    user1.display();

    User User3 = ++user2;
    User3.display();
    
    user2 += 10;
    user2.display();
}