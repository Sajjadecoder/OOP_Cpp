#include <iostream>
using namespace std;
class Point
{
private:
    int x, y;

public:
    Point() { Point(1, 1); }
    Point(int i, int j);
    Point(const Point &t);
};
Point::Point(int i, int j)
{
    x = i;
    y = j;
    cout << x << " " << y << " Normal Constructor called\n ";
}
Point::Point(const Point &t)
{
    y = t.y;
    cout << y << " " << "Copy Constructor called\n ";
}
int main()
{
    Point *t1, *t2;
    t1 = new Point(10, 15);//10 15 normal constructor called
    t2 = new Point(*t1);
    cout<<endl;//15 copy constructor called
    Point t3 = *t1;//15 copy constructor called
    Point t4;//1 1 Normal constructor called
    t4 = t3;
    return 0;
}