// P4.9: Area and circumference of a circle
#include <iostream>
using namespace std;

int main()
{
    const double PI = 3.14159;
    double radius;
    cout << "Radius: ";
    cin >> radius;

    double area = PI * radius * radius;
    double circumference = 2 * PI * radius;
    cout << "Area          = " << area << endl;
    cout << "Circumference = " << circumference << endl;
    return 0;
}
