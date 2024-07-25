#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Course
{
    string name, grade;
    static double sgpa;
    double weightage, gpa, creditHours;

public:
    Course(const string &n, double wtg, double crd) : name(n), weightage(wtg), creditHours(crd)
    {
        assignGrade();
    }
    string getCoursename() { return name; }
    string getGrade() { return grade; }
    double getSGPA() { return sgpa; }
    double getGPA() { return gpa; }
    double getWeightage() { return weightage; }
    void assignGrade()
    {
        if (weightage >= 89.5)
        {
            grade = "A+";
            gpa = 4;
        }
        else if (weightage >= 85.5)
        {
            grade = "A";
            gpa = 4;
        }
        else if (weightage >= 81.5)
        {
            grade = "A-";
            gpa = 3.67;
        }
        else if (weightage >= 77.5)
        {
            grade = "B+";
            gpa = 3.33;
        }
        else if (weightage >= 73.5)
        {
            grade = "B";
            gpa = 3;
        }
        else if (weightage >= 69.5)
        {
            grade = "B-";
            gpa = 2.67;
        }
        else if (weightage >= 65.5)
        {
            grade = "C+";
            gpa = 2.33;
        }
        else if (weightage >= 61.5)
        {
            grade = "C";
            gpa = 2;
        }
        else if (weightage >= 57.5)
        {
            grade = "C-";
            gpa = 1.67;
        }
        else if (weightage >= 53.5)
        {
            grade = "D+";
            gpa = 1.33;
        }
        else if (weightage >= 49.5)
        {
            grade = "D";
            gpa = 1;
        }
        else
        {
            grade = "F";
            gpa = 0;
        }
        sgpa += (gpa / 4) * 0.25 * creditHours;
    }
    void displayCurrentCourse()
    {
        cout << name << "\t\t\t" << grade << "\t\t\t" << gpa << endl;
    }
};

double Course::sgpa = 0;
class Student
{
    string sName, rollNum;
    vector<Course> courses;

public:
    Student(const string &n, string rn) : sName(n), rollNum(rn) {}
    void addCourse(string cName, double wtg, double crd)
    {
        courses.push_back(Course(cName, wtg, crd));
    }
    void displayAll()
    {
        cout << "Student Name: " << sName << endl
             << "Roll Number: " << rollNum << endl
             << endl;
        cout << "Course name"
             << "\t\t"
             << "Grade"
             << "\t\t\t"
             << "GPA"
             << "\t\t" << endl;
        for (int i = 0; i < courses.size(); i++)
        {

            courses[i].displayCurrentCourse();
        }
        cout << endl
             << "SGPA: " << courses[1].getSGPA() << endl;
    }
};
int main()
{
    string name, rollnum;
    cout << "Student's name: ";
    getline(cin, name);
    cout << "Student's roll number: ";
    getline(cin, rollnum);
    Student s1(name, rollnum);
    int choice;
    cout << "1. Add Course\n2. Display result\nChoice: ";
    cin >> choice;
    while (choice != 2)
    {
        string cName;
        double credits, wtg;
        cout << "Enter Course Name: ";
        cin.ignore();
        getline(cin, cName);
        cout << "Enter weightage obtained: ";
        cin >> wtg;
        cout << "Enter credit hours: ";
        cin >> credits;
        s1.addCourse(cName, wtg, credits);
        cout << "Course added!\nEnter choice(1,2): ";
        cin >> choice;
    }
    s1.displayAll();

    return 0;
}