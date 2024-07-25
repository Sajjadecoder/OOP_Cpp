#include<bits/stdc++.h>
#include<string>
using namespace std;
/*The class attributes should include the person’s first name, a unique ID, and date of birth
(consisting of separate attributes for the month, day, and year of birth). The ID will be the
third digit of your student ID. You are required to input your student ID and extract
the third digit.
 Your class should have a constructor that receives this data as a parameter. For each
attribute, provide set and get functions.*/

struct date
{
    string month;
    int day,year;
};


class heartBeat{
    string firstName;
    char id;
    struct date DOB;
    public:
    
    heartBeat(string firstName,char id,struct date thisDate){
        this->firstName = firstName;
        this->id= id;
        this->DOB = thisDate;
    }
    string getName(){
        return this->firstName;
    }
    string getMonth(){
        return DOB.month;
    } 
    char getID(){
        return id;
    }
    int getYear(){
        return DOB.year;
    }
    int getDay(){
        return DOB.day;
    }
    void setName(string n){
        this->firstName = n;
    }
    void setDate(struct date d){
             this->DOB = d;
    }
    void setID(char pID){
        this->id = pID;

    }
    int getAge(string thisyear){
        int tempYear = stoi(thisyear);
        return tempYear-DOB.year;
    }
    
};


int main(){
    string userID,name;
    cout<<"Enter ID: ";cin>>userID;
    cout<<"Enter name: ";cin>>name;
    int index = 0;
    struct date userDate;
    cout<<"Enter day of birth: ";cin>>userDate.day;
    cout<<"Enter month of birth: ";cin>>userDate.month;
    cout<<"Enter year of birth: ";cin>>userDate.year;
    
    while (userID[index]!='-')
    {
        index++;
    }
    
    heartBeat obj1(name,userID[index+3],userDate);
    cout<<"Name: "<<obj1.getName()<<endl;
    cout<<"ID: "<<obj1.getID()<<endl;
    //cout<<"Name: "<<obj1.getName()<<endl;
}