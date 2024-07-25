#include <iostream>
#include <string>
using namespace std;
class RationalNumber
{
    int numerator, denominator;

public:
    RationalNumber() {}
    RationalNumber(int x, int y) : numerator(x)
    {
        while (y < 1)
        {
            if (y <= 0)
            {
                cout << "Invalid denominator\nRe-enter: ";
                cin >> y;
            }
        }
    }
    RationalNumber operator+(RationalNumber &obj)
    {
        RationalNumber temp;
        if (this->denominator == obj.denominator)
        {
            temp.numerator = this->numerator + obj.numerator;
            temp.denominator = this->denominator;
            return temp;
        }
        temp.numerator = (this->numerator * obj.denominator + obj.numerator * this->denominator);
        temp.denominator = this->denominator * obj.denominator;
        return temp;
    }
    bool operator==(RationalNumber &r)
    {
        if (r.numerator == this->numerator && r.denominator == this->denominator)
        {
            return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &out, RationalNumber &obj)
    {
        out << obj.numerator <<"/"<<obj.denominator;
        return out;
    }
};
int main()
{

    return 0;
}