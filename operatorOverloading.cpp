#include <iostream>
#include <string>
using namespace std;

class Box
{
    int length, vol;

public:
    Box() {}
    Box(int l)
    {
        length = l;
        vol = l * l * l;
    }
    int getVolume() { return vol; }
    Box operator+(const Box &obj)
    {
        Box temp;
        temp.vol = this->vol + obj.vol;
        return temp;
    }
};
int main()
{
    Box box1(4);
    Box box2(5);
    Box box3 = box1 + box2;
    cout << box3.getVolume();

    return 0;
}