#include <iostream>
#include <string>
using namespace std;
template<class T>
class Property
{
protected:
    string address, type, size, ownersName;
    double totalAmount;

public:
    Property() {}
    Property(string add, string t, string s, string o) : address(add), type(t), size(s), ownersName(o) {
        totalAmount = 0;
    }
    string getAddress(){return address;}
    string getType(){return type;}
    string getSize(){return size;}
    string getOwnerName(){return ownersName;}

    int operator ++(){
        if (this->type == "neighbourhood features")
        {
            totalAmount = 10000.0 *1.4;
            return totalAmount;
        }
        else{
            cout<<"dfdfd";
            return -1;
        }
    }
};
template <class T>
class ResidentialProperty:public Property<T>{
    int bedrooms,bathrooms;

    public:
    ResidentialProperty(){}
    ResidentialProperty(int bed,int bath,string add, string t, string s, string o):Property<T>(add,t,s,o)  {
        if (t!="neighbourhood features")
        {
            cout<<"Invalid type\nRe-Enter: ";
            getline(cin,t);
        }
        this->type = t;
        
        bedrooms = bed;
        bathrooms = bath;
    }

    
};
template <class T>
class CommercialProperty:public Property<T>{
    double rentalRates;

    public:
    CommercialProperty(){}
    CommercialProperty(double rates,string add, string t, string s, string o):Property<T>(add,t,s,o)  {
        if (t!="lease terms")
        {
            cout<<"Invalid type\nRe-Enter: ";
            getline(cin,t);
        }
        this->type = t;
        ;
        rentalRates = rates;
    }


    
};


int main()
{
    CommercialProperty<double> obj(200.0,"ABC","lease terms","120x150","john");
    int x = ++obj;
    cout<<x<<endl;
    cout<<endl;
    ResidentialProperty <int> obj2(2,3,"ABC","neighbourhood features","120x150","john");
    int y = ++obj2;
    cout<<"y: "<<y;
    return 0;
}