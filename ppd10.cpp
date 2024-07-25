#include<iostream>
using namespace std;
class Player
{
private:
    string category,playerID;
    int score;
public:
    Player(string pID) {
        this->playerID = pID;
        this->score = 0;
        this->category = "Not Qualified";
    }
    Player(){}
    string getPlayerID(){
        return playerID;
    }
    string getCategory(){
        return category;
    }
    int getScore(){
        return score;

    }
    void setPlayerID(){
        int check = 0;
        string thisPlayerID;
        cout<<"Enter ID: ";
        while (check == 0)
        {
            cin>>thisPlayerID;
            if (thisPlayerID.length()<=15 && thisPlayerID.length()>=4)
            {
                check = 1;
                this->playerID = thisPlayerID;
            }else{
            
                cout<<"Enter valid ID: ";
            }           
        }        
    }
    int setScore(int score){
        if (score>150 || score <0)
        {
            cout<<"Invalid score\n";
            return 0;
        }
        else
        {
            this->score = score;
        }
        return 1;    
    }
    void setCategory(){
        if (this->score>120)
        {
            this->category = "Advanced";
        }
        else if (this->score>80)
        {
            this->category = "Intermediate";
        }
        else if (this->score>50)
        {
            this->category = " Beginner";
        }
        else{ this->category = "Not Qualified";}
    }
};
void createPlayer(){
    Player JoannePlayer;
    JoannePlayer.setPlayerID();
    int x = 0;int score;
    cout<<"Enter score: ";
    while (x==0)
    {
        cin>>score;
        x = JoannePlayer.setScore(score);
        if (x==0)
        {
            cout<<"Enter valid score: ";
        }
        
    }
    JoannePlayer.setCategory();
    cout<<JoannePlayer.getCategory()<<endl;
    cout<<JoannePlayer.getPlayerID()<<endl;
    cout<<JoannePlayer.getScore();
}
int main(){
    createPlayer();
    
}