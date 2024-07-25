#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    string s = "sajjad ahmed";
    string s2;
    // ofstream out("sample.txt");//write
    // out<<s;
    // out.close();
    // ifstream in("sample.txt");//read
    // getline(in,s2);
    // cout<<"Read string: ";
    // cout<<s2;
    // in.close();
    cout<<"Enter a name: ";
    getline(cin,s2);
    ofstream Write("sample.txt");
    while (s2!= "sajjad")
    {
        Write<<s2<<endl;
        cout<<"Enter a name(again): ";
        getline(cin,s2);
        
    }
    Write.close();
    ifstream input("sample.txt");
    while (!(input.eof()))
    {
        string line;
        getline(input,line);
        cout<<line<<endl;
    }
    

    return 0;
}