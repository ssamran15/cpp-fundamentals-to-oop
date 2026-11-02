// P5.13: Area of a triangle by Heron's formula
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cout << "Enter the three sides: ";
    cin >> a >> b >> c;

    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    cout << "Area = " << area << endl;
    return 0;
}
