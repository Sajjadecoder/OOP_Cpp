#include<iostream>
#include<string>
using namespace std;
class Complex{
    public:
    double real,imaginary;
    Complex(){}
    Complex(double r,double i):real(r),imaginary(i){}
    Complex sum(Complex &a,Complex &b){
        return Complex(a.real+b.real,a.imaginary+b.imaginary);
    }
    Complex subtract(Complex &a,Complex &b){
        return Complex(a.real-b.real,a.imaginary-b.imaginary);
    }
    Complex product(Complex &a,Complex &b){
        return Complex(a.real*b.real,a.imaginary*b.imaginary);
    }
    Complex calculate(Complex &a,Complex &b){
        int choice;
        cout<<"1. Add\n2. Difference\n3. Product\nChoice: ";
        cin>>choice;
        if (choice==1)
        {
            return sum(a,b);
        }else if (choice==2)
        {
            return subtract(a,b);
        }else{
            return product(a,b);
        }
        
        
    }

};

int main(){
    
    double r,i;
    cout<<"Real of num1: ";cin>>r;
    cout<<"Img of num1: ";cin>>i;
    Complex n1 = Complex(r,i);
    cout<<"Real of num2: ";cin>>r;
    cout<<"Img of num2: ";cin>>i;
    Complex n2(r,i);
    Complex res = res.calculate(n1,n2);
    cout<<"Real: "<<res.real<<endl;
    cout<<"Img: "<<res.imaginary<<endl;

    return 0;
}
