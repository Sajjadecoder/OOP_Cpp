#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Size: ";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int i=0;
    int j=0;
    while (i<n)
    {
        if (arr[j]>arr[j+1])
        {
            int temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
        if (j==n-2)
        {
            j=0;
            i++;
        }else
        {
            j++;
        }
    }
    cout<<"Final\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    
}