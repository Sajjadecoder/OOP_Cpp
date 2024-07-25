#include<iostream>
#include<string>
using namespace std;
class Distance{
    int feet,inch;
    public:
    Distance(){}
    Distance(int x,int y):feet(x),inch(y) {}
    friend istream &operator >> (istream &in,Distance &dist)
    {
        in>>dist.feet>>dist.inch;
        return in;
    }
    friend ostream &operator << (ostream &out, const Distance &dist)
    {
        out<<"Feet: "<<dist.feet<<" Inches: "<<dist.inch;
        return out;
    }
};
int main(){
    Distance d1(10,20);
    Distance d2;
    cin>>d2;
    cout<<d1;
    cout<<d2;
    return 0;
}