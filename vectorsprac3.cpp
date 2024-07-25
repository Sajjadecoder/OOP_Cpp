#include<iostream>
#include<string>
#include<vector>
using namespace std;
class course{
    string courseName,courseID;
    public:
    course(){}
    course(string cn,string ci):courseID(ci),courseName(cn) {}
    void display(){
        cout<<"Name: "<<courseName<<endl;
        cout<<"ID: "<<courseID<<endl;
    }
    string getID(){return courseID;}
};
class student{
    vector <course> array;
    string studentName;
    public:
    student(){}
    student(string name):studentName(name) {}
    void addCourse(course &obj){
        array.push_back(obj);
    }
    void removeCourse(string id){
        for (int i = 0; i <array.size(); i++)
        {
            if (id==array[i].getID())
            {
                array.erase(array.begin()+i); // removes the course that matches the id
            }
            
        }
        
    }
    void displayCourses(){
        for (int i = 0; i <array.size(); i++)
        {
            array[i].display();
            cout<<endl;
        }
        
    }

};
int main(){
    student s1("John");
    course c1("OOP","CS1001");
    course c2("MVC","MT1001");
    course c3("DLD","EE1001");
    s1.addCourse(c1);
    s1.addCourse(c2);
    s1.addCourse(c3);
    cout<<"Before courses removal\n\n";
    s1.displayCourses();
    s1.removeCourse("MT1001");
    cout<<"After courses removal\n\n";
    s1.displayCourses();
    return 0;
}