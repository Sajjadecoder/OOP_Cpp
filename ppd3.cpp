#include<iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
class character
{
private:
    string name;
    int skill,health,shield;

public:

    character(string pName){
        srand(time(0));
        this->name =pName;
        this->skill = 0;
        this->health = 50;
        this->shield = rand()%25 +1;
    }
    character(){}
    int getSkill(){
        return this->skill;
    }
    int setSkill(int userSkill){
        if (userSkill<10 || userSkill>25)
        {
            return -1;
        }
        this->skill+=userSkill;
        if (this->skill>200)
        {
            this->skill = 200;
            return 0;
        }
        return 1;
    }
};
int main(){
    character characterArray[5] ;
    for (int i = 0; i < 5; i++)
    {
        characterArray[i] = character(" ");
    }
    characterArray[0]=character("victory");
    
}
