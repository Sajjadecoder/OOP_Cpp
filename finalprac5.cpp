#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Plant{
    protected:
    string name,type;
    double price;
    public:
    Plant(){}
    Plant(string n,string t,double p):name(n),type(t),price(p) {}
    string getName(){return name;}
    string getType(){return type;}
    double getPrice(){return price;}




};

class CompanyLawnPlant:public Plant{
    int quantityNeeded;
    int maintainanceLevel;
    public:
    CompanyLawnPlant(){}
    CompanyLawnPlant(string name,string type,double price,int qty,int m):Plant(name,type,price),quantityNeeded(qty),maintainanceLevel(m) {}
    double calculateCost(){
        return double(quantityNeeded)*price;
    }
    
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Type: "<<type<<endl;
        cout<<"Quantity: "<<quantityNeeded <<" "<<maintainanceLevel<< endl;
        cout<<"Price: "<<price<<endl;
    }

};
class FamilyParkPlant:public Plant{
    int quantityNeeded;
    int  maintainanceLevel;
    public:
    FamilyParkPlant(){}
    FamilyParkPlant(string name,string type,double price,int qty,int m):Plant(name,type,price),quantityNeeded(qty),maintainanceLevel(m) {}
    double calculateCost(){
        return double(quantityNeeded)*price;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Type: "<<type<<endl;
        cout<<"Quantity: "<<quantityNeeded<<" "<<maintainanceLevel<< endl;
        cout<<"Price: "<<price<<endl;
    }

};
template<class T,class U>
class Project{
    double totalCostOfCompanyLawn;
    double totalCostOfFamilyPark;
    vector<T> companyLawns;
    vector<U>familyParks;
    public:
    Project(){
        totalCostOfCompanyLawn = 0;
        totalCostOfFamilyPark = 0;
    }
     void operator + (T &obj){
        companyLawns.push_back(obj);
        
    }
    void operator + (U &obj){
        familyParks.push_back(obj);
    }
    void operator << (int x){
        cout<< "Plants for company lawn 1:\n";
        for (int i = 0; i < companyLawns.size(); i++)
        {
            companyLawns[i].display();
            totalCostOfCompanyLawn+= companyLawns[i].calculateCost();
        }
        cout<<"Total cost of company lawn: "<<totalCostOfCompanyLawn<<endl;
        cout<< "\nPlants for family park 1:\n";
        for (int i = 0; i < familyParks.size(); i++)
        {
            familyParks[i].display();
            totalCostOfFamilyPark+= familyParks[i].calculateCost();
        }
        cout<<"Total cost of family park: "<<totalCostOfFamilyPark<<endl;
    
    }

};

int main(){
    Project<CompanyLawnPlant,FamilyParkPlant> p1;
    FamilyParkPlant family("Rose Bush","Shrub",5,50,2);
    FamilyParkPlant family2("Maple Tree","Tree",40,20,1);
    CompanyLawnPlant company1("Marigold","Flower",2.5,100,2);
    CompanyLawnPlant company2("Oak tree","tree",30,10,1);

    
    p1+family;
    p1+family2;
    p1+company1;
    p1+company2;
    p1<<1;

    return 0;
}