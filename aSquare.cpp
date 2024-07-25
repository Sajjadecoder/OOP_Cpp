#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t,x1,x2,x3,x4,y1,y2,y3,y4;
    cin>>t;
    int array[t];
    int answer;
    for (int i = 0; i < t; i++)
    {
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
        cin>>x4>>y4;
        if (x1!=x2)
        {
            answer = (x1-x2)*(x1-x2);
            
        }else if (x1!=x3)
        {
            answer = (x1-x3)*(x1-x3);
        }
        else
        {
            answer = (x1-x4)*(x1-x4);
        }
        array[i] = answer;

        
    }
    for (int i = 0; i < t; i++)
    {
        cout<<array[i]<<endl;
    }
    

}