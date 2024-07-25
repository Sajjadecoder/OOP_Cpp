#include<iostream>
#include<string>
using namespace std;
class Seat
{
    int row,seatNumber;
    bool isReserved;
    public:
    Seat(){}
    Seat(int row,int num,bool isR){
        this->row = row;
        this->seatNumber = num;
        isReserved = isR;
    }
    void reserve(){isReserved = true;}
    void cancelReservation(){isReserved = false;}
    bool getStatus(){
        return isReserved;
        
    }
    int getRow(){return row;}
    int getSeatNumber(){return seatNumber;}

};
class Theatre{
    Seat **array;
    int rows,col;
    bool isValidSeat(int row,int seat){
        for (int i = 0; i <rows; i++)
        {
            for (int j = 0; j <col; j++)
            {
                if (array[i][j].getRow() ==row && array[i][j].getSeatNumber()==seat)
                {
                    return true;
                }
                
            }
            
        }
        return false;
        
    }
    public:
    Theatre(){}
    void initializeSeats(int numRows,int numSeatsPerRow){
        rows = numRows;
        col = numSeatsPerRow;
        array = new Seat*[numRows];
        for (int i = 0; i < numRows; i++)
        {
            array[i] = new Seat[numSeatsPerRow];
        }
        int count = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                array[i][j] = Seat(i,count,false);
                count++;
            }
            
        }
        
    }
    void viewAvailableSeats(){
        cout<<"Available seats:\n";
        for (int i = 0; i <rows; i++)
        {
            for (int j= 0; j < col; j++)
            {
                if (array[i][j].getStatus()==false)
                {
                    cout<<"Seat Number "<<array[i][j].getSeatNumber() <<" of row "<<i+1<<" is available\n";
                }
                
            }
            
        }
        cout<<"\nReserved seats:\n";
        for (int i = 0; i <rows; i++)
        {
            for (int j= 0; j < col; j++)
            {
                if (array[i][j].getStatus()==true)
                {
                    cout<<"Seat Number "<<array[i][j].getSeatNumber() <<" of row "<<i+1<<" is Reserved\n";
                }
                
            }
            
        }
    }
    void reserve(int row,int seat){
        
        try{
            if (!(isValidSeat(row,seat)))
            {
                throw -1;
            }
            
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (array[i][j].getSeatNumber()==seat && i == row)
                    {
                        if (array[i][j].getStatus()==true)
                        {
                            cout<<"hi"<<endl;
                            throw false;
                        }
                        
                        array[i][j].reserve();
                        cout<<"Seat reserved successfully\n";
                    }
                    
                }
                
                
            }
            
            
        }catch(bool status){
                cout<<"This seat is already reserved \n";
        }
        catch(int x){
            cout<<"Invalid entry\n";
        }
    }
    void cancelReservation(int row , int seat){
        try
        {
            if (!isValidSeat(row,seat))
            {
                throw -1;
            }
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j <col;j++)
                {
                     if (array[i][j].getSeatNumber()==seat && i == row)
                    {
                        if (array[i][j].getStatus()==false)
                        {
                            throw false;
                        }
                        
                        array[i][j].cancelReservation();
                        cout<<"Seat reserved successfully\n";
                    }
                }
                
            }
            
            
        }catch(bool e){
            cout<<"Seat is already available\n";
        }
        catch(int e)
        {
            cout<<"Invalid entry\n";
        }
        
    }
};

int main(){
    Theatre t;
    t.initializeSeats(5,5);
    t.viewAvailableSeats();
    cout<<endl<<endl;
    t.reserve(1,7);
    t.reserve(0,4);
    t.viewAvailableSeats();
    return 0;
}