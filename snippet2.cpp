#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Pair
{
private:
    T first;
    T second;

public:
    Pair(T f, T s) : first(f), second(s) {}

    T sum() const
    {
        return first + second;
    }
    template <typename U>
    friend U average(const Pair<T>& p);
};


template <typename T, typename U>
U average(const Pair<T>& p) {
    return (p.first + p.second) / static_cast<U>(2);
}

int main()
{
    Pair<int> p(5, 7);
    cout << "Sum: " << p.sum() << endl;
    cout << "Average: " << average<int, double>(p) << endl; 
}
