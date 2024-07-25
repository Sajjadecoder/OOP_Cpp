#include<iostream>
using namespace std;
int main(){
    int sum = 0;
    
    int arr[5];

    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter num: ";cin>>arr[i];

    }
    int max = 0;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
        sum+=arr[i];

    }
    cout<<"Max number: "<<max<<endl;
    cout<<"sum: "<<sum;
}