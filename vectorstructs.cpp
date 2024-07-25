#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct info{
    string title,author,genre;
    int year;

};
void addBook(vector<struct info> &lib){
    struct info temp;
    cin.ignore();
    cout<<"Enter title: ";
    getline(cin,temp.title);
    cout<<"Enter author: ";
    getline(cin,temp.author);
    cout<<"Enter genre: ";
    getline(cin,temp.genre);
    cout<<"Enter year: ";
    cin>>temp.year;
    lib.push_back(temp);
}
void updateBook(vector<struct info> &lib){
    struct info temp;
    
    cout<<"Enter title(previous): ";getline(cin,temp.title);
    for (int i = 0; i < lib.size(); i++)
    {
        if (temp.title==lib[i].title)
        {
            fflush(stdin);
            cout<<"Enter author: ";getline(cin,temp.author);
            cout<<"Enter genre: ";getline(cin,temp.genre);
            cout<<"Enter year: ";cin>>temp.year;
            lib[i] = temp;
            break;
        }
        
    }
    
}
void removeBook(vector<struct info> &lib){
    string title;
    cout<<"Title of the book to be removed: ";
    cin.ignore();
    getline(cin,title);
    for (int i = 0; i < lib.size(); i++)
    {
        if (title==lib[i].title)
        {
            lib.erase(lib.begin()+i);
        }
        
    }
    
}
void displayAll(vector<struct info> &lib){
    for (int i = 0; i < lib.size(); i++)
    {
        cout<<"Title: "<<lib[i].title<<endl;
        cout<<"Author: "<<lib[i].author<<endl;
        cout<<"Genre: "<<lib[i].genre<<endl;
        cout<<"Publication Year: "<<lib[i].year<<endl<<endl;
    }
    
}
int main(){
    vector<struct info> library;
    int choice = 1; 
    cout<<"1. Add book\n2. Update book info\n3. Remove a book\n4. Display all\n0. Exit\n";    
    while (choice != 0)
    {
        cout<<"Enter your choice: ";

        cin>>choice;
        switch (choice)
        {
        case 1:
            addBook(library);
            break;
        case 2: 
            updateBook(library);
            break;
        case 3:
            removeBook(library);break;
        case 4: 
            displayAll(library);break;
        case 0:
            break;
        default:
            cout<<"Invalide choice\n";
            break;
        }
    }
}