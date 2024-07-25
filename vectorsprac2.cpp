#include<iostream>
#include<vector>

using namespace std;
struct details
{
    int age;
    string name;
};
;
int main(){
    vector<struct details> person;
    for (int i = 0; i < 3; i++)
    {
        struct details temp;

        //string n;int age;
        fflush(stdin);
        cout<<"Name: ";cin>>temp.name;
        cout<<"Age: ";cin>>temp.age;

        person.push_back(temp);
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<person[i].name<<person[i].age<<endl;
    }
    
    vector <int> arr;
    int n;
    cout<<"Size: ";cin>>n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cout<<"Number : ";cin>>num; 
        arr.push_back(num);
    }
    int num;cout<<"Delete num: ";
    cin>>num;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]==num)
        {
            arr.erase(arr.begin()+i);
        }
        
    }
    cout<<"Final elements\n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<endl;
    }
}