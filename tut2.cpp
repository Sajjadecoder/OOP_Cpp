#include<bits/stdc++.h>
using namespace std;
class puzzlePlayer
{
    private:
        string name;
        string playerID;
        int score;
    
    public:
    
    puzzlePlayer(){
        playerID = "PL12a3";
        name = "";
        score = 0;

    
    }
public:
    string getPlayerID(){
        return playerID;
    }
    
    string getName(){
        return name;
    }
    int getScore(){
        return score;
    }
    int setPlayerID(string id){
        if (id.length()==6 && id[0]=='P' && id[1]=='L')
        {
            playerID = id;
            return 1;
        }
        else{
            return 0;
        }

    }
    
    void setName(string n){
        name = n;
    }

    void setScore(int num){
        score = num;
    }



};
int main(){
    string name;
    puzzlePlayer Pplayer;
    cout<<"name plis: ";

    cin>>name;
    int reVal = Pplayer.setPlayerID(name);
    if (reVal == 1)
    {
        cout<<"Name valid\n";
    }else{
        cout<<"invalid";
    }
    
}
