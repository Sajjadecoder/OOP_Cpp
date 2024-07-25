#include<iostream>
#include<string>
using namespace std;

class Loan{
    protected:
    double loanAmount,interestRate,duration;
    public:
    Loan(){}
    Loan(double lA,double iR,double dur){
        
        try{
            if (lA<=0)
            {
                throw lA;
            }
            loanAmount=lA;
            
        }catch(double loan){
            cout<<loan <<" <=0\n";
        }
        try{
            if (iR< 0 || iR>10)
            {
                throw iR;
            }
            interestRate = iR;
            
        }catch(double interest){
            cout<<interest <<" is is out of limit\n";
        }
        duration = dur;
    }
    double getLoanAmount(){return loanAmount;}
    double getInterestRate(){return interestRate;}
    double getDuration(){return duration;}
    virtual double calculateMonthlyPayment() const = 0;
    virtual double display()const = 0;
    friend class LoanManager;
    friend void loanUtils(const Loan& loan){}
};
class CarLoan: public Loan{
    public:
    CarLoan(){}
    CarLoan(double lA,double iR,double dur):Loan(lA,iR,dur){}
    double calculateMonthlyPayment(){
        double payment = (loanAmount * (1+(interestRate/100)) * (duration/12));
        cout<<"Monthly interest payment: "<<payment<<endl;

    }
    double display()const{
        cout<<"Loan Amount: "<<loanAmount<<endl;
        cout<<"Interest Rate: "<<interestRate<<endl;
        cout<<"Duration(months): "<<duration<<endl;
    }

};
class HomeLoan: public Loan{
    public:
    HomeLoan(){}
    HomeLoan(double lA,double iR,double dur):Loan(lA,iR,dur){}
    double calculateMonthlyPayment(){
        double payment = (loanAmount * (1+(interestRate/100)) * (duration/12));
        cout<<"Monthly interest payment: "<<payment<<endl;

    }
    double display()const{
        cout<<"Loan Amount: "<<loanAmount<<endl;
        cout<<"Interest Rate: "<<interestRate<<endl;
        cout<<"Duration(months): "<<duration<<endl;
    }
};
class BusinessLoan: public Loan{
    public:
    BusinessLoan(){}
    BusinessLoan(double lA,double iR,double dur):Loan(lA,iR,dur){}
    double calculateMonthlyPayment()const override{
        double payment = (loanAmount * (1+(interestRate/100)) * (duration/12));
        cout<<"Monthly interest payment: "<<payment<<endl;

    }
    double display()const override{
        cout<<"Loan Amount: "<<loanAmount<<endl;
        cout<<"Interest Rate: "<<interestRate<<endl;
        cout<<"Duration(months): "<<duration<<endl;
    }
};

class LoanManager{
    public:
    LoanManager(){}
    void approvingLoan( Loan &obj){
        cout<<"Enter loan amount: ";
        double amount;
        cin>>amount;

        if (amount>100000)
        {
            cout<<"Cannot give loan\n";
        }else{
            obj.loanAmount = amount;
            cout<<"Loan Approved\n";
        }
        
    }
    void calculatePayment(Loan &obj){
        cout<<obj.interestRate/100.0<<endl;
        cout<<obj.duration<<endl;
        cout<<obj.loanAmount<<endl;
        cout<<"Total interest payment: "<< obj.loanAmount * (1.0+(obj.interestRate/100.0)) * obj.duration<<endl;
    }
};
int main(){
    BusinessLoan obj(1000.0,5.0,10.0);
    cout<<obj.getLoanAmount()<<endl<<endl;
    LoanManager manager;
    manager.calculatePayment(obj);
    return 0;
}   