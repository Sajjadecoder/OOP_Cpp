#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <cctype>
#include <windows.h>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
using namespace std;
class Teacher;
class Section;
class Course
{
    string courseName, courseID;
    int creditHours;
    string grade;
    double weightage, gpa;

public:
    Course() {}
    Course(string name, string ID, int crd) : courseName(name), courseID(ID), creditHours(crd) {}
    void displayCourseData()
    {
        cout << "Name: " << courseName << endl;
        cout << "ID: " << courseID << endl;
        if (weightage == 0 || gpa == 0 || grade == "")
        {
            cout << "No Info About GPA Yet";
        }
        else
        {
            cout << "Weightage: " << weightage << endl;
            cout << "GPA: " << gpa << endl;
            cout << "Grade: " << grade << endl
                 << endl;
        }
    }
    double getGPA() { return gpa; }
    double getWeightage() { return weightage; }
    string getID() { return courseID; }
    string getCourseName() { return courseName; }
    int getCredits() { return creditHours; }
    void assigngrade(string name)
    {

        cout << "Enter total weightage for " << courseName << " of " << name << ": ";
        cin >> weightage;
        while (weightage > 100 || weightage < 0)
        {
            cout << "Weightage must be between 0-100\nRe-Enter: ";
            cin >> weightage;
        }

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
    }
};
class Person
{
protected:
    string name, contactNumber;
    int age;

public:
    Person() {}
    Person(string pName, string pNum, string pAge) : name(pName)
    {
        int stop = 0;
        while (stop == 0)
        {
            stop = 1;
            if (pAge.length() >= 3)
            {
                cout << RED << "Invalid age\nRe-Enter: ";
                stop = 0;
            }
            else
            {

                for (int i = 0; i < pAge.length(); i++)
                {
                    if (!(pAge[i] >= '1' && pAge[i] <= '9'))
                    {
                        cout << "Invalid age\nRe-Enter: ";
                        stop = 0;
                        break;
                    }
                }
            }
            if (stop == 0)
            {
                getline(cin, pAge);
            }
        }
        age = stoi(pAge);
        stop = 0;
        while (stop == 0)
        {

            stop = 1;
            if (pNum.length() != 11)
            {
                cout << "Re-enter Contact number(11 digits only): ";
                stop = 0;
            }
            else
            {

                for (int i = 0; i < pNum.length(); i++)
                {
                    if (pNum[i] < '0' || pNum[i] > '9')
                    {
                        cout << "Invalid Number\nRe-Enter(only numeric characters): ";
                        stop = 0;
                        break;
                    }
                }
            }
            if (stop == 0)
            {
                getline(cin, pNum);
            }
        }
        contactNumber = pNum;
    }
    string getName() { return name; }
    string getNumber() { return contactNumber; }
    int getAge() { return age; }
    virtual void displayUserData() = 0;
};

class Student : public Person
{
protected:
    double sgpa;
    string ID, department;
    int resizeCount = 3;

public:
    Course *studentCourses;
    int count;
    Student()
    {
        sgpa = 0;
    }
    void checkValidDepartment(string dep)
    {
        int stop = 0;
        while (stop == 0)
        {
            stop = 1;
            for (int i = 0; i < dep.size(); i++)
            {
                dep[i] = toupper(dep[i]);
            }
            if (dep != "CS" && dep != "CY" && dep != "SE" && dep != "AI" && dep != "BA" && dep != "EE" && dep != "FINTECH")
            {
                cout << "Department entered is invalid or isnt offered in our campus\nRe-Enter: ";
                stop = 0;
            }
            if (stop == 0)
            {
                getline(cin, dep);
            }
        }
        department = dep;
    }
    void checkValidID(string id)
    {
        int stop = 0;
        while (stop == 0)
        {
            stop = 1;
            if (id.length() > 8 || id[2] != 'K' || id[3] != '-' || id[0] != '2' || id[1] != '3')
            {
                cout << "Follow the format(23K-XXXX): ";
                stop = 0;
            }
            else
            {
                for (int i = 4; i < id.length(); i++)
                {
                    if (id[i] < '0' || id[i] > '9')
                    {
                        cout << "Enter a valid ID(eg. 23K-0428): ";
                        stop = 0;
                        break;
                    }
                }
            }
            if (stop == 0)
            {
                getline(cin, id);
            }
        }
        ID = id;
    }
    Student(string name, string num, string age, string id, string dep) : Person(name, num, age), count(0)
    {
        checkValidID(id);
        checkValidDepartment(dep);
        sgpa = 0;
        studentCourses = new Course[resizeCount];
    }
    string getStudentID() { return ID; }
    void addCourse()
    {
        string newID, newName;
        int newCrdts;
        cout << "Enter Course ID: ";
        getline(cin, newID);
        int stop = 0;
        while (stop == 0)
        {
            stop = 1;
            for (int i = 0; i < count; i++)
            {
                if (studentCourses[i].getID() == newID)
                {
                    cout << "This course is already registered\nEnter new Course ID: ";
                    stop = 0;
                    break;
                }
            }
            if (stop == 0)
            {
                getline(cin, newID);
            }
        }
        cout << "Enter Course Name: ";
        getline(cin, newName);
        cout << "Enter credits for " << newName << " : ";
        cin >> newCrdts;
        while (newCrdts <= 0 || newCrdts > 3)
        {
            cout << "Enter valid credit hours(between 1 and 3 inclusive): ";
            cin >> newCrdts;
        }
        cin.ignore();
        if (count == resizeCount)
        {
            resizeCount *= 2;
            Course *temp = new Course[resizeCount];
            for (int i = 0; i < count; i++)
            {
                temp[i] = studentCourses[i];
            }
            delete[] studentCourses;
            studentCourses = temp;
        }

        studentCourses[count++] = Course(newName, newID, newCrdts);
    }
    void generateFeeVoucher()
    {
        int fees = 0;
        int totalCredits = 0;

        for (int i = 0; i < count; i++)
        {

            totalCredits += studentCourses[i].getCredits();
        }
        cout << "Student Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Total credits for this semester: " << totalCredits;
        cout << "\nTution Fee: " << 9000 * totalCredits << endl;
        cout << "Activity Charges: 2500\n";
        cout << "Total Fee: " << 9000 * totalCredits + 2500 << endl;
        cout << "----------------------------------------\n";
    }
    void calculateSGPA()
    {
        for (int i = 0; i < count; i++)
        {
            double gpa = (studentCourses[i].getGPA() / 4) * studentCourses[i].getCredits();
            sgpa += gpa;
        }
    }
    double getSGPA() { return sgpa; }

    void displayUserData()
    {
        cout << "Student's Name: " << name << endl;
        cout << "Roll Number: " << name << endl;
        cout << "Contact No.: " << this->contactNumber << endl;
        cout << "Age: " << age << endl;
        cout << "Department: " << this->department << endl;
        cout << "Courses info:\n";
        for (int i = 0; i < count; i++)
        {
            cout << "Course " << i + 1 << endl;
            studentCourses[i].displayCourseData();
            cout << endl;
        }
        calculateSGPA();
        cout << "SGPA: " << sgpa << endl;
    }
};
class Teacher : public Person
{
protected:
    double salary;
    string courseID;
    const double payPerCreditHour = 50000;

public:
    Teacher(string name, string num, string age, string ID) : Person(name, num, age), salary(0), courseID(ID) {}
    Teacher() {}
    void calculateSalary(Section &sec);
    void displayUserData()
    {
        cout << "Name: " << name << endl;
        cout << "Contact Number: " << contactNumber << endl;
        cout << "Age: " << this->age << endl;
        cout << "Salary: " << this->salary << endl;
    }
    void assignGrades(Section &sec);
};
class Section
{
    string sec;
    vector<Student> students;

public:
    Section() {}
    Section(string Sec) : sec(Sec) {}
    void fee()
    {
        string rolnum;
        cout << "Enter Roll Number\n";
        getline(cin, rolnum);
        for (int i = 0; i < students.size(); i++)
        {
            if (rolnum == students[i].getStudentID())
            {
                students[i].generateFeeVoucher();
                return;
            }
        }
        cout << "Roll Number Not found\n";
    }
    void addStudentInClass()
    {
        try
        {
            if (students.size() > 10)
            {
                throw -1;
            }
            string name, age, num, id, dep;
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter your age: ";
            getline(cin, age);
            cout << "Enter your contact number: ";
            getline(cin, num);
            cout << "Enter your ID: ";
            getline(cin, id);
            cout << "Enter your department: ";
            getline(cin, dep);
            students.push_back(Student(name, num, age, id, dep));
        }
        catch (...)
        {
            cout << "No more space to add students in the class\n";
        }
    }
    void removeStudent()
    {
        fflush(stdin);
        string id;
        cout << "Enter Student's ID for removal: ";
        getline(cin, id);
        int stop = 0;
        while (stop == 0)
        {
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].getStudentID() == id)
                {
                    string name = students[i].getName();

                    students.erase(students.begin() + i);
                    cout << name << " removed successfully\n";
                    stop = 1;
                }
            }
            if (stop == 0)
            {
                cout << "ID not found\nTry again: ";
                getline(cin, id);
            }
        }
    }
    void display()
    {
        for (int i = 0; i < students.size(); i++)
        {
            students[i].displayUserData();
            Sleep(2000);
            system("cls");
        }
        CheckRanks();
    }
    void CheckRanks()
    {
        vector<string> deanList;
        vector<string> rectorList;
        double avg = 0;
        for (int i = 0; i < students.size(); i++)
        {
            avg += students[i].getSGPA();
        }
        avg /= students.size();
        string maxID, maxName;
        double gpa = 0;
        for (int i = 0; i < students.size(); i++)
        {
            if (gpa < students[i].getSGPA())
            {
                gpa = students[i].getSGPA();
                maxName = students[i].getName();
                maxID = students[i].getStudentID();
            }
            if (students[i].getSGPA() >= 3.5 && students[i].getSGPA() < 4)
            {
                deanList.push_back(students[i].getStudentID());
            }
            if (students[i].getSGPA() == 4)
            {
                rectorList.push_back(students[i].getStudentID());
            }
        }

        cout << "Student with highest SGPA: " << maxName << " (" << maxID << ")\nClass Average SGPA: " << avg << endl;
        if (deanList.size() != 0)
        {
            cout << "\nStudents who made it to dean's list:\n";
            for (int i = 0; i < deanList.size(); i++)
            {
                cout << i + 1 << ". " << deanList[i] << endl;
            }
        }
        if (rectorList.size() != 0)
        {
            cout << "Students who made it to Rector's list:\n";
            for (int i = 0; i < rectorList.size(); i++)
            {
                cout << i + 1 << ". " << rectorList[i] << endl;
            }
        }
    }
    void addCourses()
    {
        for (int i = 0; i < students.size(); i++)
        {
            cout << "How many courses you want to add for " << students[i].getStudentID() << "?\nEnter count: ";
            int count;
            cin >> count;
            cin.ignore();
            for (int j = 0; j < count; j++)
            {
                students[i].addCourse();
            }
        }
    }
    friend class Teacher;
};
void Teacher::assignGrades(Section &sec)
{
    for (int i = 0; i < sec.students.size(); i++)
    {
        for (int j = 0; j < sec.students[i].count; j++)

        {
            if (sec.students[i].studentCourses[j].getID() == courseID)
            {
                sec.students[i].studentCourses[j].assigngrade(sec.students[i].getName());
            }
        }
    }
}
void Teacher::calculateSalary(Section &sec)
{
    for (int i = 0; i < sec.students.size(); i++)
    {
        for (int j = 0; j < sec.students[i].count; j++)
        {
            if (sec.students[i].studentCourses[j].getID() == this->courseID)
            {
                salary = payPerCreditHour * sec.students[i].studentCourses[j].getCredits();
                return;
            }
        }
    }
}
int main()
{
    Section sec("BCS-2F");
    vector<Teacher> Arr;
    int check = 0;
    string pass;
    string choice;
    do
    {
        system("cls");
        cout << YELLOW << "WELCOME TO EDU-SYNC!\n";
        cout << RED << "\nMenu:\n";
        cout << BLUE << "0. Teacher's Menu!(Make sure to add Students first)\n";
        cout << BLUE << "1. Add Student\n";                // s+t
        cout << BLUE << "2. Display Students\n";           // s+t
        cout << BLUE << "3. Assign courses to Students\n"; // s+t
        cout << BLUE << "4. Print FeeVoucher\n";           // s+t
        cout << BLUE << "5. Exit\n";
        cout << BLUE << "Enter your choice: ";
        getline(cin, choice);
        Sleep(600);
        system("cls");
        cout << MAGENTA << "LOADING";
        for (int i = 0; i < 3; i++)
        {
            Sleep(100);
            cout << ".";
            Sleep(100);
        }
        system("cls");
        if (choice == "1") // Add Student
        {
            check = 1;
            cout << "Adding a new student\n";
            Sleep(500);
            sec.addStudentInClass();
            system("cls");
            cout << "Student Added Successfully\n";
            Sleep(1200);
            system("cls");
        }

        else if (choice == "2") // Display Students
        {
            system("cls");
            sec.display();
        }
        else if (choice == "3")
        {
            if (check == 0)
            {
                cout << "No Students in the class\nEnter Students!\n";
            }
            else
            {
                sec.addCourses();
                cout << "Courses added successfully\n";
                Sleep(1200);
                system("cls");
            }
        }
        else if (choice == "4")
        {
            if (check == 0)
            {
                cout << "No Students in the class\nEnter Students!\n";
            }
            else
            {
                sec.fee();
            }
        }
        else if (choice == "5")
        {
            cout << "Exiting...\n";
            Sleep(600);
        }

        else if (choice == "0")
        {
            int c = 0;
            cout << "Enter Password To Access!\nPassword: ";
            do
            {
                getline(cin, pass);
                if (pass != "mypassword")
                {
                    cout << "Password Incorrect\n\n";
                }
                else
                {
                    c = 1;
                    cout << "Access Granted!\n";
                    Sleep(750);
                    system("cls");
                }
            } while (c == 0);

            if (c == 1)
            {
                int Choice;
                try
                {
                    if (Arr.size() == 0)
                    {
                        throw 0;
                    }
                    cout << "Teacher History:\n";
                    for (int i = 0; i < Arr.size(); i++)
                    {
                        cout << i + 1 << ". " << Arr[i].getName() << endl;
                    }
                    cout << "Kindly Select One Or Press 0 For New Login\n";
                    cin >> Choice;
                    if (Choice == 0)
                    {
                        throw 0;
                    }
                    Choice--;
                }
                catch (...)
                {
                    string tName, tNum, tAge, courseTaught;
                    cout << "Enter Teacher's name: ";
                    getline(cin, tName);
                    cout << "Enter Teacher's Phone No.: ";
                    getline(cin, tNum);
                    cout << "Enter Teacher's Age: ";
                    getline(cin, tAge);
                    cout << "Enter Course ID taught by the teacher: ";
                    getline(cin, courseTaught);
                    Teacher Teacher1(tName, tNum, tAge, courseTaught);
                    Arr.push_back(Teacher1);
                    Choice = Arr.size() - 1;
                }

                string select;
                do
                {
                    cout << "A. Teacher's Details!\n";
                    cout << "B. Assign Grades\n";
                    cout << "C. Remove Student\n";
                    cout << "X. Exit Teacher's Menu\n";
                    cout << "Select Option:";
                    cin >> select;
                    if (select == "A" || select == "a")
                    {
                        Arr[Choice].calculateSalary(sec);
                        Arr[Choice].displayUserData();
                    }

                    else if (select == "B" || select == "b") // Assign Grades
                    {
                        cout << "Assigning Grades...\n";
                        Sleep(600);
                        Arr[Choice].assignGrades(sec);
                        cout << "Grades Assigned Successfully!\n";
                        fflush(stdin);
                    }
                    else if (select == "C"  || select == "c") // Remove Student
                    {
                        if (check == 0)
                        {
                            cout << "No Students in the class\nEnter Students!\n";
                        }
                        else
                        {
                            sec.removeStudent();
                        }
                    }
                    else if (select == "X" || select == "x")
                    {
                        cout << "Returning to Student's Menu...\n";
                        Sleep(600);
                    }
                    else
                    {
                        // cout << "Invalid Choice Entered!\n";
                    }
                    cin.ignore();
                } while (select != "X" || select != "x");
            }
        }

        else
        {
            cout << "Invalid Choice Entered!\n";
        }

    } while (choice != "5");

    return 0;
}