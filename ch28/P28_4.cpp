// P28.4: Counting shapes with typeid, the largest circle with dynamic_cast
#include <iostream>
#include <typeinfo>
using namespace std;

class Shape
{
public:
    virtual ~Shape() {}
    virtual double area() const = 0;
};

class Circle : public Shape
{
private:
    double r;

public:
    Circle(double radius) : r(radius) {}
    double area() const override { return 3.14159 * r * r; }
    double getRadius() const { return r; }
};

class Rectangle : public Shape
{
private:
    double l, w;

public:
    Rectangle(double length, double width) : l(length), w(width) {}
    double area() const override { return l * w; }
};

int main()
{
    const int MAX = 20;
    Shape *shapes[MAX];
    int n;
    cout << "Number of shapes: ";
    cin >> n;
    if (n < 1 || n > MAX)
        return 1;

    for (int i = 0; i < n; i++)
    {
        char kind;
        cout << "Shape " << i + 1 << " (c radius / r length width): ";
        cin >> kind;
        if (kind == 'c')
        {
            double r;
            cin >> r;
            shapes[i] = new Circle(r);
        }
        else
        {
            double l, w;
            cin >> l >> w;
            shapes[i] = new Rectangle(l, w);
        }
    }

    int circles = 0, rectangles = 0;
    for (int i = 0; i < n; i++)
    {
        if (typeid(*shapes[i]) == typeid(Circle))
            circles++;
        else if (typeid(*shapes[i]) == typeid(Rectangle))
            rectangles++;
    }
    cout << "Circles: " << circles << ", rectangles: " << rectangles << endl;

    const Circle *largest = nullptr;
    for (int i = 0; i < n; i++)
    {
        const Circle *c = dynamic_cast<const Circle *>(shapes[i]);
        if (c != nullptr && (largest == nullptr || c->getRadius() > largest->getRadius()))
            largest = c;
    }
    if (largest != nullptr)
        cout << "Largest circle: radius " << largest->getRadius() << ", area " << largest->area() << endl;
    else
        cout << "There are no circles" << endl;

    for (int i = 0; i < n; i++)
        delete shapes[i];
    return 0;
}
