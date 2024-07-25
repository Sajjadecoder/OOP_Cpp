#include<iostream>
#include<random>
using namespace std;
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <thread>
void display(char array[][5]){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <5; j++)
        {
            cout << array[i][j]<<" ";
        }
        cout<<endl;
        
    }
    cout<<endl<<endl;
}
int game(char array[][5],int *count){
    srand(time(0));
    
    int clash = 0;
    while (clash == 0)
    {
        int xPlayer = rand()%5;
        int yPlayer = rand()%5;

        int xFood = rand()%5;
        int yFood = rand()%5;
        if (xFood==xPlayer && yFood == yPlayer)
        {
            clash = 1;
            array[xPlayer][yPlayer] = 'W';
            display(array);
            cout<<"Clash detected :)\n";
            array[xPlayer][yPlayer] = '.';
            return 1;
        }else{
            array[xPlayer][yPlayer] = 'P';
            array[xFood][yFood] = 'F';
            display(array);
            //sleep for 2 sec;
            array[xPlayer][yPlayer] = '.';
            array[xFood][yFood] = '.';
        }
        
    }
    
}
using namespace std;
int main(){
    char array[5][5];
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            array[i][j] = '.';
        }
        
    }
    
    while (count!=3)
    {
        int retVal = game(array,&count);
        count++;
    }
    



}