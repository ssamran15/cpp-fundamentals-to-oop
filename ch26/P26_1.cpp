// P26.1: Rectangle and Circle derived from Shape
#include <iostream>
#include <string>
using namespace std;

class Shape
{
protected:
    string name;

public:
    Shape(string n) : name(n) {}
};

class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double l, double w) : Shape("Rectangle"), length(l), width(w) {}
    double area() const { return length * width; }
    double perimeter() const { return 2 * (length + width); }

    void show() const
    {
        cout << name << " " << length << " x " << width << ": area " << area()
             << ", perimeter " << perimeter() << endl;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    double area() const { return 3.14159 * radius * radius; }
    double perimeter() const { return 2 * 3.14159 * radius; }

    void show() const
    {
        cout << name << " of radius " << radius << ": area " << area()
             << ", perimeter " << perimeter() << endl;
    }
};

int main()
{
    Rectangle r(12, 7.5);
    Circle c(4);
    r.show();
    c.show();
    return 0;
}
