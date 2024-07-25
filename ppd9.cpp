#include<iostream>
using namespace std;
#include<string>
class printAccount{
    private:
        string firstName,lastName,printID;
        int credits;
    public:
        printAccount(string f,string l,string p)
        {
            firstName = f;
            lastName = l;
            printID = p;
            credits = 50;
        }
        string getName(){
            string fullName = firstName + " "+lastName;
            return fullName;
        }
        void setFirstName(string fn){
            this->firstName = fn;
        }
        
        void setLastName(string fn){
            this->lastName = fn;
        }
        
        void setPrintID(string fn){
            this->printID = fn;
        }
        void AddCredits(int MoneyInput){
            if (MoneyInput>=20)
            {
                credits = credits+50 + (MoneyInput*25);
            }
            else if (MoneyInput>=10)
            {
                credits = credits+25 + (MoneyInput*25);
            }
            else{
                credits+=(MoneyInput*25);
            }
            
        }  
        string getPrintID(){
            return this->printID;
        }
};
printAccount studentAccounts[1000] = printAccount("  ","  ","  ");
int NumberStudents = 0;
void createID(string fName,string lName){
    
    for (int i = 0; i < fName.length(); i++)
    {
        fName[i] = tolower(fName[i]);
    }
    
    for (int i = 0; i < lName.length(); i++)
    {
        lName[i] = tolower(lName[i]);
    }
    int currentNum = 1;
    string fullName = fName.substr(0,3) + lName.substr(0,3) + "1";
    cout<<"str: "<<fullName<<endl;
    int repeat = 1;
    while (repeat==1)
    {
        repeat = 0;
        for (int i = 0; i <1000; i++)
        {
            if (fullName==studentAccounts[i].getPrintID())
            {
                repeat = 1;
                break;
            }
        
        }
        if (repeat==1)
        {
            currentNum++;
            string num = to_string(currentNum);
            fullName = fName.substr(0,3) + lName.substr(0,3) + num;
            cout<<"\nnew id: "<<fullName<<endl;
        }
        else
        {
            studentAccounts[NumberStudents].setPrintID(fullName);
            NumberStudents++;   
        }
        
    
    }
    
    


}   

int main(){
    string first,last;
    for (int i = 0; i < 1000; i++)
    {
        studentAccounts[i]= printAccount("  ","  ","  ");
    }
    
    cout<<"Enter first name: ";cin>>first;
    cout<<"Enter last name: ";cin>>last;
    createID(first,last);
    
    cout<<"Enter first name: ";cin>>first;
    cout<<"Enter last name: ";cin>>last;
    createID(first,last);
    cout<<"Enter first name: ";cin>>first;
    cout<<"Enter last name: ";cin>>last;
    createID(first,last);
}