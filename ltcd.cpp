#include<iostream>
using namespace std;
int firstMissingPositive(int nums[],int size){
    int check = 0;int min= nums[0];
    for (int i = 0; i < size; i++)
    {
        if (nums[i]==1)
        {
            check = 1;
            
        }
        
    }
    if (check==0)
    {
        return 1;
    }
    
    for (int i = 0; i < size; i++)
    {
        if (nums[i]<min)
        {
            min = nums[i];  
        }    }
        int sum = min;
            for (int i = 0; i < size; i++)
            {
                int flag = 0;
                for (int j = 0; j < size; j++)
                {
                    if (nums[j]!=min && nums[j]==min+1)
                    {
                        flag = 1;
                        min++;
                        break;
                    }
                    
                }
                if (flag==0)
                {
                    min++;
                    return min;
                }
                
                
            }        
    
}
int main(){
    int size;
    cout<<"Size: ";
    cin>>size;
    int nums[size];
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];

    }
    int retVal = firstMissingPositive(nums,size);
    cout<<"Missing is: "<<retVal;
}