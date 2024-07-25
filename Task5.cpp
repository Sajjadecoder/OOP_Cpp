//23K-0754
#include<iostream>
using namespace std;
struct details{
    string eventName,date,venue,organizer;
};
int n;
void addEvent(struct details *events){
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout<<"Enter Event "<<i+1 << " name: ";
        cin>>events[i].eventName;
        cout<<"Enter date of event "<<i+1 << " : ";
        cin>>events[i].date;
        cout<<"Enter Venue of event "<<i+1 << " : ";
        cin>>events[i].venue;
        cout<<"Enter Organizer of event "<<i+1 << " : ";
        cin>>events[i].organizer;
    }
}
void displayAll(struct details *events){
    string date;
    cout<<"Enter date to display Complete information: ";
    fflush(stdin);
    getline(cin,date);
    for (int i = 0; i < n; i++)
    {
        if (date==events[i].date)
        {
            cout<<"Event name: "<<events[i].eventName<<endl;
            cout<<"Date: "<<events[i].date<<endl;
            cout<<"Venue: "<<events[i].venue<<endl;
            cout<<"Organizer: "<<events[i].organizer<<endl;
            break;
        }
        
    }
}
void displayOnDate(struct details *events){
    string date;
    int found = 0;
     cout<<"Enter date to display Events on a particular date: ";
     fflush(stdin);
    getline(cin,date);
    for (int i = 0; i < n; i++)
    {
        if (date==events[i].date)
        {
            cout<<"Event name: "<<events[i].eventName<<endl;
            found=1;
        }
        
    }
    if (found ==0)
    {
        cout<<"No events found at this date"<<endl;
    }
    

}
int main(){
    struct details *events = nullptr ;
    int choice;
    cout<<"1. Add event\n2.Display all\n3.Display Events on a particular date\n0.exit\nEnter your choice: ";
    cin>>choice;
    while (choice!=0)
    {
        
        switch (choice)
        {
        case 1:
            cout<<"Enter the count of events to add: ";cin>>n;
            events = new struct details[n];
            addEvent(events);
            break;
        case 2:
            displayAll(events);
            break;
        case 3:
            displayOnDate(events);
            break;
        case 0:
            delete [] events;
            break;
        default:
            cout<<"Invalid choice entered\n";
            break;
        }
        if (choice!=0)
        {
            cout<<"Enter choice: ";
            cin>>choice;
        }
    }
        
}