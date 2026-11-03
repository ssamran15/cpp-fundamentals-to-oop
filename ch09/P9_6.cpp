// P9.6: Overloaded area functions
#include <iostream>
#include <cmath>
using namespace std;

double area(double r);
double area(double length, double width);
double area(double a, double b, double c);

int main()
{
    double r, length, width, a, b, c;

    cout << "Radius of the circle: ";
    cin >> r;
    cout << "Length and width of the rectangle: ";
    cin >> length >> width;
    cout << "Three sides of the triangle: ";
    cin >> a >> b >> c;

    cout << "Circle area = " << area(r) << endl;
    cout << "Rectangle area = " << area(length, width) << endl;
    cout << "Triangle area = " << area(a, b, c) << endl;
    return 0;
}

double area(double r)
{
    const double PI = 3.14159;
    return PI * r * r;
}

double area(double length, double width)
{
    return length * width;
}

double area(double a, double b, double c)
{
    double s = (a + b + c) / 2;          // Heron's formula
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
