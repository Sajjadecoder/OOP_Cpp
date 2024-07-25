#include <iostream>
#include <string>
using namespace std;
class Employee
{
    const float MAX_SALARY;
    float salary;
    string name;
    static int nextEmployeeID;

public:
    Employee(float sal, string eName) : name(eName), MAX_SALARY(sal) { nextEmployeeID++; }
    static int generateEmployeeID()
    {
        name = "sasas";//error since name isnt static member
        nextEmployeeID +=2;//no error since it is a static var
        return nextEmployeeID + 1;
    }
    void setSalary(float sal)
    {
        if (sal > MAX_SALARY)
        {
            salary = MAX_SALARY;
        }
        else
        {
            salary = sal;
        }
    }
    void displayEmployeeInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << nextEmployeeID << endl;
        cout << "salary: " << salary << endl
             << endl;
    }
};
int Employee::nextEmployeeID = 0;
int main()
{
    Employee obj1(25000, "Will");
    obj1.setSalary(18550.5);
    obj1.displayEmployeeInfo();
    Employee obj2(25000, "Frill");
    obj2.setSalary(25001);
    obj2.displayEmployeeInfo();
}