#include<iostream>
using namespace std;
#include<vector>
vector<int> findMinMax(vector<int> &v){
    int min = 100;int max=0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]>max)
        {
            max = v[i];
        }
        
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]<min)
        {
            min= v[i];
        }

        
    }
    vector<int> result;
    result.push_back(min);
    result.push_back(max);
    return result;
}
int main(){
    int size;
    cout<<"Size of Array : ";
    cin>>size;
    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        int n;
        cin>>n;
        v.push_back(n);
    }
    vector<int> resVal = findMinMax(v);
    cout<<"Min "<<resVal[0]<<endl;
cout<<"Max "<<resVal[1]<<endl;
}