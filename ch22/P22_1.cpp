// P22.1: A Circle composed of a Point centre
#include <iostream>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    double getX() const { return x; }
    double getY() const { return y; }
    void show() const { cout << "(" << x << ", " << y << ")"; }
};

class Circle
{
private:
    Point centre;               // composition: a Circle has a Point
    double radius;

public:
    Circle(double cx, double cy, double r) : centre(cx, cy), radius(r) {}

    bool contains(const Point &p) const
    {
        double dx = p.getX() - centre.getX();
        double dy = p.getY() - centre.getY();
        return dx * dx + dy * dy <= radius * radius;    // no square root needed
    }

    void show() const
    {
        cout << "Circle with centre ";
        centre.show();
        cout << " and radius " << radius << endl;
    }
};

int main()
{
    Circle c(2, 3, 5);
    c.show();

    Point points[4] = { Point(2, 3), Point(5, 7), Point(6, 7), Point(-4, 3) };
    for (int i = 0; i < 4; i++)
    {
        points[i].show();
        cout << (c.contains(points[i]) ? " is inside" : " is outside") << endl;
    }
    return 0;
}
