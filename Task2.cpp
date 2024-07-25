//23K-0754
#include<iostream>
using namespace std;



int main(){
    int n;
    cout<<"Enter the number of students: ";cin>>n;
    int students[n];
    int maths[n];
    int science[n];
    int english[n];
    
    for (int i = 0; i < n; i++)
    {
        cout<<"Maths marks of student "<<i+1<<": ";cin>>maths[i];
        cout<<"Science marks of student "<<i+1<<": ";cin>>science[i];
        cout<<"English marks of student "<<i+1<<": ";cin>>english[i];
        students[i] = maths[i]+science[i]+english[i]; 
    }
    float avg;
    char grade;
    cout<<"Results\n";
    for (int i = 0; i < n; i++)
    {
        avg = students[i]/3.0;
        if (avg>=90.0)
        {
            grade = 'A';
        }
        else if (avg>=80.0)
        {
            grade = 'B';
        }
        
        else if (avg>=70.0)
        {
            grade = 'C';
        }
        
        else if (avg>=60.0)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }
        cout<<"English Marks of Student "<<i+1<<" : "<<english[i]<<endl;
        cout<<"Science Marks of Student "<<i+1<<" : "<<science[i]<<endl;
        cout<<"Maths Marks of Student "<<i+1<<" : "<<maths[i]<<endl;
        cout<<"Total Marks of Student "<<i+1<<" : "<<students[i]<<endl;
        cout<<"Average Marks of Student "<<i+1<<" : "<<avg<<endl;
        cout<<"Grade of Student "<<i+1<<" : "<<grade<<endl;
        cout<<endl;
               
    }
    
     
}