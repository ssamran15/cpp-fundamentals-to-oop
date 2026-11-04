// P28.8: Are two shapes of the same kind?
#include <iostream>
#include <typeinfo>
using namespace std;

class Shape
{
public:
    virtual ~Shape() {}
};

class Circle : public Shape {};
class Square : public Shape {};

bool sameKind(const Shape &a, const Shape &b)
{
    return typeid(a) == typeid(b);          // the real (dynamic) types are compared
}

int main()
{
    Circle c1, c2;
    Square s1;

    cout << "c1 and c2: " << (sameKind(c1, c2) ? "same kind" : "different kinds") << endl;
    cout << "c1 and s1: " << (sameKind(c1, s1) ? "same kind" : "different kinds") << endl;
    cout << "s1 and s1: " << (sameKind(s1, s1) ? "same kind" : "different kinds") << endl;
    return 0;
}
