// P17.1: Rectangle, first with separate functions, then with member functions
#include <iostream>
using namespace std;

// Version 1: data in a structure, functions outside it
struct Rectangle
{
    double length;
    double width;
};

double area(const Rectangle &r)
{
    return r.length * r.width;
}

double perimeter(const Rectangle &r)
{
    return 2 * (r.length + r.width);
}

// Version 2: the functions are members of the structure
struct Rectangle2
{
    double length;
    double width;

    double area()
    {
        return length * width;          // members are used directly
    }

    double perimeter()
    {
        return 2 * (length + width);
    }
};

int main()
{
    double l, w;
    cout << "Length and width: ";
    cin >> l >> w;

    Rectangle r1 = {l, w};
    cout << "Version 1: area = " << area(r1) << ", perimeter = " << perimeter(r1) << endl;

    Rectangle2 r2 = {l, w};
    cout << "Version 2: area = " << r2.area() << ", perimeter = " << r2.perimeter() << endl;
    return 0;
}
