#include<iostream>
using namespace std;
int main(){
    /*int n;
    cout<<"Size: ";cin>>n;
    int *ptr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>*(ptr + i);
    }
    for (int i = 0; i <n; i++)
    {
        cout<<"Val "<<i+1<<" is "<<*(ptr+i)<<endl;
    }
    delete[] ptr;
    */
   int n;
   cout<<"Initial size: ";cin>>n;
   int *ptr = new int[n];
   for (int i = 0; i < n; i++)
   {
        cin>>*(ptr+i);
   }
   int new_n;
   cout<<"Enter new size: ";cin>>new_n;
   int *ptr2 = new int[new_n];
   for (int i = 0; i < n; i++)
   {
        *(ptr2 + i) = *(ptr + i);
   }
   delete[] ptr;
   ptr=ptr2;
   ptr2 = NULL;
   cout<<"New values\n";
   for (int i = n; i < new_n; i++)
   {
        cin>>*(ptr+i);
   }
   cout<<"Final values\n";
   for (int i = 0; i < new_n; i++)
   {
        cout<<*(ptr+i);
   }
   delete[] ptr;
   
   
}