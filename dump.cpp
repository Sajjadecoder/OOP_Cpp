

//runtime error in the code

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"n: ";cin>>n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    int t;
    cout<<"t: ";cin>>t;
    int left = 0,right = 1;
    int stop = 0;
    while (left<right && stop ==0)
    {
        if (right==n-1&&left==n-1)
        {
            stop = 1;
        }
        else if (array[left]+array[right]==t)
        {
            cout<<left<<","<<right<<endl;
        }else if (right==n-1)
        {
            left++;
            right==left+1;
            
        }
        else
        {
            right++;
        }
        
        
        
        
        
    }
    
    
}