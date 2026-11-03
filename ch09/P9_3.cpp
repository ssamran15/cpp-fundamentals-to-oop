// P9.3: Area and circumference of a circle
#include <iostream>
using namespace std;

void circle(double r, double &area, double &circumference);

int main()
{
    double r, area, circumference;
    cout << "Enter the radius: ";
    cin >> r;
    circle(r, area, circumference);
    cout << "Area = " << area << endl;
    cout << "Circumference = " << circumference << endl;
    return 0;
}

void circle(double r, double &area, double &circumference)
{
    const double PI = 3.14159;
    area = PI * r * r;
    circumference = 2 * PI * r;
}
