// P21.1: const member functions and a const Circle object
#include <iostream>
using namespace std;

class Circle
{
private:
    double radius;

public:
    Circle(double r) : radius(r > 0 ? r : 1) {}

    void setRadius(double r)                // changes the object: not const
    {
        if (r > 0)
            radius = r;
    }

    double getRadius() const { return radius; }
    double area() const { return 3.14159 * radius * radius; }
    double circumference() const { return 2 * 3.14159 * radius; }
};

void printCircle(const Circle &c)
{
    // only const member functions can be called through c
    cout << "Radius " << c.getRadius() << ": area " << c.area()
         << ", circumference " << c.circumference() << endl;
}

int main()
{
    Circle ordinary(5);
    const Circle fixed(2.5);

    printCircle(ordinary);
    printCircle(fixed);

    ordinary.setRadius(7);
    printCircle(ordinary);
    // fixed.setRadius(7);      // error: setRadius is not a const member function
    return 0;
}
