#include<iostream>
using namespace std;

class foodItems
{
private:
    string name,code;
    int cost;


public:
    foodItems(string nameP,string codeP,int costP ){
        this->name = nameP;
        this->code = codeP;
        this->cost = costP;
    };
    string getCode(){
        return this->code;
    }
    string getName(){
        return this->name;

    }
    void setname(string n){
        this->name = n;
    }
    int getCost(){
        return this->cost;
    }
};

class vendingMachine{
    private: 
        foodItems items[4];
        int moneyIn;
        
    public:
        /*vendingMachine(string item1,string item2,string item3,string item4){
            items[0].setname(item1);
            items[1].setname(item2);
            items[2].setname(item3);
            items[3].setname(item4);
        }*/
          vendingMachine(string item1, string item2, string item3, string item4) : items{
            foodItems(item1, "code1", 10),
            foodItems(item2, "code2", 15),
            foodItems(item3, "code3", 20),
            foodItems(item4, "code4", 25)
            
        }
    {
        this->moneyIn = 0;
    }


        void insertMoney(int val){
            this->moneyIn=this->moneyIn+val;
        }

        int checkValid(string code){
            int found = 0;
            for (int i = 0; i <4; i++)
            {
                if (items[i].getCode()==code)
                {
                    if (moneyIn<items[i].getCost())
                    {
                        return -2;
                    }
                    else{
                        return i;
                    }
                    
                }
                
            }
            return -1;
        }

};


int main(){
    vendingMachine machine1("chocolate","sweets","sandwich","apple");
}