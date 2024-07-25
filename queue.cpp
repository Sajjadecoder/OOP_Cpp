#include<iostream>
#include<string>
using namespace std;

class queue{
    int *array;
    int start,end;
    public:
    queue(){
        array = new int[5];
        start=-1;
        end=-1;
    }
    void enqueue(int num){
        if (end==5-1)
        {
            cout<<"Queue full\n";

        }else{
            end++;
            array[end] = num;
            if (start==-1)
            {
                start = 0;

            }
            
        }
        
    }
    void dequeue()
    {
        if (start==-1 || end==-1)
        {
            cout<<"Queue empty\n";
        }else {
            //array[start] = NULL;
            start++;

        }

        
    }
    void display(){
        for (int i = start; i <= end; i++)
        {
            cout<<array[i]<<" ";
        }cout<<endl;
        
    }
};
int main(){
    queue q1;
    q1.enqueue(5);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(2);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.display();
    return 0;
}