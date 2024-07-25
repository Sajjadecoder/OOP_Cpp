#include<iostream>
#include<string>
using namespace std;
class course{
    string courseName;
    string courseCode;
    int creditHours;
    public:
    course(){}
    course(string name,string code,int crd):courseName(name),courseCode(code),creditHours(crd) {}
    string getCourseName(){return courseName; }
    string getCourseCode(){return courseCode;}
    int getCredits(){return creditHours;}

};
class student{
    string name,id;
    int age;
    course *courses;
    int count;
    int resizeCount=5;
    public:
    student(){}
    student(string sname,string sid,int sage):name(sname),id(sid),age(sage),count(0) {
        courses = new course[resizeCount];
    }
    string getName(){return name;}
    string getID(){return id;}
    int getAge(){return age;}
    void addCourse(string name,string cID,int crd){
        if (count == resizeCount)
        {
            resizeCount*=2;
            course *temp= new course[resizeCount];
            for (int i = 0; i < count; i++)
            {
                temp[i] = courses[i];
            }
            delete [] courses;
            courses =temp;
            

        }
        courses[count] = course(name,cID,crd);
        count++;        
        
    }
    void dropCousre(string name){
        course *temp = new course[count-1];
        int j=0;
        for (int i = 0; i < count; i++)
        {
            if (courses[i].getCourseName()!=name)
            {
                temp[j++] = courses[i];
            }
            
        }
        delete [] courses;
        courses = temp;
        count--;
        
    }
    void display(){
        cout<<"Student name: "<<name<<endl;
        cout<<"Student id: "<<id<<endl;
        cout<<"Age: "<<age<<endl<<endl<<"Courses details: \n";
        for (int i = 0; i < count; i++)
        {
            cout<<"Course name: "<<courses[i].getCourseName()<<endl;
            cout<<"Course Code: "<<courses[i].getCourseCode()<<endl;
            cout<<"Credit Hours: "<<courses[i].getCredits()<<endl<<endl;
        }
        
    }


    ~student(){
        delete [] courses;
    }
};
int main(){
    student obj("sajjad","23k-0754",19);
    obj.addCourse("oop","cs1001",3);
    obj.addCourse("dld","ee1001",3);
    obj.addCourse("mvc","ss1001",3);
    obj.addCourse("EW","cs1001",2);
    obj.addCourse("icp","cs1001",2);
    obj.addCourse("tsc","cs1001",1);
    obj.addCourse("oop lab","cs1001",1);
    obj.display();
    obj.dropCousre("mvc");
    cout<<endl<<"Display After dropping mvc\n\n\n";
    obj.display();
}
