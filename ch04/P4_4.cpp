// P4.4: Area of a triangle
#include <iostream>
using namespace std;

int main()
{
    double base, height;
    cout << "Base and height: ";
    cin >> base >> height;

    double area = 0.5 * base * height;
    cout << "Area of the triangle = " << area << endl;
    return 0;
}
