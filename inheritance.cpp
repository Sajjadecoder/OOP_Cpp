#include<iostream>
using namespace std;
class parent{
    int varA;
    public:
    int varB;
        void setA(int a){
        varA = a;
    }
    void setC(int c){
        varC = c;
    }

    protected:
    int varC;
    parent(){}
    int getA(){
        return varA;
    }
    int getC(){
        return varC;
    }
};
class child:public parent{
    int varD;
    public:
    int varE;
    child(){}
    int getvarA(){
        
        return getA();
    }
    int getVarC(){
        return varC;
    }
    protected:
    int varF;
    
    void setF(int f){
        varF = f;
    }
};
int main(){
    child obj;
    obj.setA(10);
    cout<<obj.getvarA();
    obj.setC(101);
    cout<<obj.getVarC();

}