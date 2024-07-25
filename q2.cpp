#include<iostream>
template<class T>
T maximum(T a,T b){
    if (a>b)
    {
        return a;
    }return b;
    
}
int main() {
int intMax = maximum(5, 10);
std::cout << "Max of 5 and 10: " << intMax <<
std::endl;
double doubleMax = maximum(3.14, 2.71);
std::cout << "Max of 3.14 and 2.71: " << doubleMax
<< std::endl;
char charMax = maximum('a', 'z');
std::cout << "Max of 'a' and 'z': " << charMax <<
std::endl;
return 0;
}