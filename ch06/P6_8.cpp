// P6.8: Valid triangle and its type
#include <iostream>
using namespace std;

int main()
{
    double a, b, c;
    cout << "Enter three sides: ";
    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a)
    {
        if (a == b && b == c)
            cout << "Equilateral triangle" << endl;
        else if (a == b || b == c || a == c)
            cout << "Isosceles triangle" << endl;
        else
            cout << "Scalene triangle" << endl;
    }
    else
        cout << "These sides cannot form a triangle" << endl;
    return 0;
}
