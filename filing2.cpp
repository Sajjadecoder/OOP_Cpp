#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class student
{
    string ID, name, gender;
    double quiz1, quiz2, mid, final, total;

public:
    student() {}
    student(string ID, string name, string g, double q1, double q2, double m, double f) : name(name), ID(ID), mid(m), quiz1(q1), quiz2(q2), final(f), gender(g)
    {
        total = quiz2 + quiz1 + mid + final;
    }
    string getName() { return name; }
    string getID() { return ID; }
    string getGender() { return gender; }
    double getquiz() { return quiz1 + quiz2; }
    double getMid() { return mid; }
    double getFinal() { return final; }
    double getTotal() { return total; }
};
void findMaxAndAvg()
{
    ifstream read("data.txt");
    string name, id, gen, maxStudent;
    double quiz, mid, fin, total;
    double maxScore = 0;
    double avg = 0.0;
    for (int i = 0; i < 5; i++)
    {
        getline(read, id);
        getline(read, name);
        getline(read, gen);
        read >> quiz >> mid >> fin >> total;
        avg += total;
        read.ignore();
        if (total > maxScore)
        {
            maxScore = total;
            maxStudent = name;
        }
    }
    read.close();
    cout << "Average: " << avg / 5 << endl;
    cout << maxStudent << " scored max marks\n";
}
void searchStudent(string id)
{
    ifstream in("data.txt");
    string sID, sName, sGen;
    double quiz, mid, fin, tot;
    for (int i = 0; i < 5; i++)
    {
        getline(in, sID);
        getline(in, sName);
        getline(in, sGen);
        in >> quiz >> mid >> fin >> tot;
        in.ignore();
        if (sID == id)
        {
            cout << "Name: " << sName << "|Gender: " << sGen << "|Quiz: " << quiz << "|Mid: " << mid << "|Final: " << fin << "|Total: " << tot << endl;
            in.close();
            return;
        }
    }
    cout << "Not found\n";
    in.close();
}
void updateRecord(string id)
{
    ifstream in("data.txt");
    ofstream out("temp.txt");
    string sID, sName, sGen;
    double quiz, mid, fin, tot;
    for (int i = 0; i < 5; i++)
    {
        getline(in, sID);
        getline(in, sName);
        getline(in, sGen);
        in >> quiz >> mid >> fin >> tot;
        in.ignore();
        if (sID != id)
        {
            out << sID << endl;
            out << sName << endl;
            out << sGen << endl;
            out << quiz << endl;
            out << mid << endl;
            out << fin << endl;
            out << tot << endl;
        }
        else
        {
            cout << "Enter new name: ";
            getline(cin, sName);
            cout << "Enter new Gender: ";
            getline(cin, sGen);
            cout << "Enter new Quiz marks: ";
            cin >> quiz;
            cout << "Enter new Mid marks: ";
            cin >> mid;
            cout << "Enter new Final marks: ";
            cin >> fin;
            tot = quiz + mid + fin;
            out << sID << endl;
            out << sName << endl;
            out << sGen << endl;
            out << quiz << endl;
            out << mid << endl;
            out << fin << endl;
            out << tot << endl;
        }
    }
    out.close();
    in.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}
int main()
{
    student s1("23K-0754", "Sajjad", "Male", 7, 8, 30, 45);
    student s2("23K-0666", "Will", "Male", 7, 8, 31, 43);
    student s3("23K-0777", "Smith", "Male", 7, 2, 30, 48);
    student s4("23K-0555", "Ahmed", "Male", 2, 5, 20, 49);
    student s5("23K-0704", "John", "Male", 7, 8, 26, 50);
    student arr[5] = {s1, s2, s3, s4, s5};
    ofstream out("data.txt");
    for (int i = 0; i < 5; i++)
    {
        out << arr[i].getID() << endl;
        out << arr[i].getName() << endl;
        out << arr[i].getGender() << endl;
        out << arr[i].getquiz() << endl;
        out << arr[i].getMid() << endl;
        out << arr[i].getFinal() << endl;
        out << arr[i].getTotal() << endl;
    }
    out.close();
    findMaxAndAvg();
    searchStudent("23K-0555");
    updateRecord("23K-0666");
    return 0;
}