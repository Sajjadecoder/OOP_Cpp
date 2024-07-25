#include<iostream>
using namespace std;
int main(){
    int left = 0;
    int right = 1;
    int size,target;
    cout<<"Enter size: ";
    cin>>size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];

    }
    cout<<"Target: ";cin>>target;
    int stop = 0;
    while (left<right && stop ==0)
    {
        if (arr[left]+arr[right]==target)
        {
            cout<<left<<","<<right;
            stop = 1;

        }
        if (right==size-1 && left ==size-1)
        {
            stop = 1;
        }
        else if (right == size-1)
        {
            left++;
            right=left+1;
        }else{
            right++;
        }
        
        
        
    }
    
    
}