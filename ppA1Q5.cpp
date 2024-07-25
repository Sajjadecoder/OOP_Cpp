#include<bits/stdc++.h>
using namespace std;
class User 
{
private:
    string userID,name;
    int age,shoe_size;
    float height;
    char gender;


public:
    User(){}
    string getName(){
        return this->name;
    }
    void setname(string n){
        this->name = n;
    }
    string getUserID(){
        return userID;
    }
    void setUserID(string id){
        int ID_Array[2];
        ID_Array[0] = stoi(id.substr(0,2));
        ID_Array[1] = stoi(id.substr(4,8));
        
        this->userID = id;
    }
    int getAge(){
        return age;
    }
    
    
    int getShoeSize(){
        return shoe_size;
    }
    void setage(int a){
        this->age = a;
    }
    void setShoeSize(int ss){
        shoe_size = ss;
    }
    float getheight(){
        return height;
    }
    char getGender(){
        return gender;
    }
    void setHeight(float h){
        this->height = h;
    }
    void setGender(char g){
        this->gender = g;
    }


};

class Shoe:public User{
    private:
        string brand,color,demographic,style;
        int size,width;
    public:
        Shoe(){};
    	string getBrand(){
            return brand;
        }

    	string getColor(){
            return color;
        }

    	string getDemographic(){
            return demographic;
        }

    	string getStyle(){
            return style;
        }
        int getSize(){
            return size;
        }
        int getWidth(){
            return width;
        }
        void setBrand(string parameter){
            brand = parameter;
        }
        
        void setDemographic(string parameter){
            demographic= parameter;
        }
        void setStyle(string parameter){
            style= parameter;
        }
        void setColor(string parameter){
            color= parameter;
        }
        void setSize(int parameter){
            size= parameter;
        }
        void setWidth(int parameter){
            width= parameter;
        }

};

int main(){
    string name,RollNum;
    int stop = 0;
    while (stop == 0)
    {
        User thisUser;
        Shoe thisShoe;
        cout<<"Enter Roll Number: ";cin>>RollNum;
        thisUser.setUserID(RollNum);
        int age;
        cout<<"Enter age: ";cin>>age;
        if (age>19)
        {
            thisShoe.setDemographic("adult");
        }
        else if (age>12)
        {
            thisShoe.setDemographic("teenager");
        }
        else if (age>5)
        {
            thisShoe.setDemographic("child");
        }
        else if (age>2)
        {
            thisShoe.setDemographic("toddler");
        }
        else{
            thisShoe.setDemographic("infant");            

        }
        
        
         
        
    }
        
}