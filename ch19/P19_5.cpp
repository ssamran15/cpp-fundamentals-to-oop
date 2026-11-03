// P19.5: Constructor delegation in a Circle class
#include <iostream>
using namespace std;

class Circle
{
private:
    double radius;

public:
    Circle(double r) : radius(r > 0 ? r : 1)
    {
    }

    Circle() : Circle(1)            // delegates to Circle(double)
    {
    }

    double area()
    {
        return 3.14159 * radius * radius;
    }
};

int main()
{
    Circle unit;            // radius 1, through delegation
    Circle big(5);

    cout << "Area of the default circle (r = 1): " << unit.area() << endl;
    cout << "Area of a circle with r = 5: " << big.area() << endl;
    return 0;
}
