#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n=8;
    vector<int> arr;
    while (n>0)
    {
        
        arr.push_back(n%2);
        n=n/2;
    }
    int ans=0;
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]==1)
        {
            ans+=pow(2,i);
        }
        
    }
    cout<<ans;
    
    
}