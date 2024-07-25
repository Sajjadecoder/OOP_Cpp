#include<iostream>
#include<string>
#include <vector>
using namespace std;
class Tour{
    protected:
    string name,destination;
    double duration;
    public:
    Tour(){}
    Tour(string n,string des,double dur):name(n),destination(des),duration(dur) {}
    virtual void calculateTicketPrice() = 0;
    virtual void scheduleTour() = 0;

};  
class AdventureTour:public Tour
{
private:
    double price;
    string activities[3] = {"ac1","ac2","ac3"};
public:
    AdventureTour() {}
    AdventureTour(string n,string des,double dur):Tour(n,des,dur) {}

    void calculateTicketPrice(){
        price = 1000.0*duration;
        cout<<"Ticket Price: "<<price<<endl;
    }
    void scheduleTour(){
        cout<<"Scheduling adventure tour...\n";
    }



};
class CulturalTour:public Tour{
    int sitesVisited;
    public:
    CulturalTour(){}
    CulturalTour(int sites,string n,string des,double dur):Tour(n,des,dur),sitesVisited(sites) {}
     void calculateTicketPrice(){
        double price= 1000.0*sitesVisited;
        cout<<"Ticket Price: "<<price<<endl;
    }
    void scheduleTour(){
        cout<<"Scheduling Cultural tour...\n";
    }
};
class WildLifeTour:public Tour{
    string expertise;
    public:
    WildLifeTour(){}
    WildLifeTour(string exp,string n,string des,double dur):Tour(n,des,dur),expertise(exp) {}
     void calculateTicketPrice(){
        double price;
        if (expertise=="professional")
        {
            price = 10000;
        }else if (expertise == "beginner")
        {
            price = 4000;
        }
        
        
        cout<<"Ticket Price: "<<price<<endl;
    }
    void scheduleTour(){
        cout<<"Scheduling WilfLife Tour...\n";
    }
};

int main(){
    AdventureTour *arr1;
    CulturalTour *arr2;
    WildLifeTour *arr3;
    arr1 = new AdventureTour[5];
    arr2 = new CulturalTour[5];
    arr3 = new WildLifeTour[5];
        double x =10;
    for (int i = 0; i < 5; i++)
    {
        arr1[i] = AdventureTour("sajjad","zoo",x);
        arr2[i] = CulturalTour(int(x+10),"sajjad","zoo",x);
        arr3[i] = WildLifeTour("beginner","sajjad","zoo",x);
        x+=10;

    }
    for (int i = 0; i <5; i++)
    {
        arr1[i].calculateTicketPrice();
        arr2[i].calculateTicketPrice();
        arr3[i].calculateTicketPrice();
    }
    
    return 0;
}