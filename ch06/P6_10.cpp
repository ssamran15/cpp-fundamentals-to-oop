// P6.10: Nature of the roots of a quadratic equation
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;

    double disc = b * b - 4 * a * c;
    if (disc > 0)
    {
        double root1 = (-b + sqrt(disc)) / (2 * a);
        double root2 = (-b - sqrt(disc)) / (2 * a);
        cout << "Roots are real and different: " << root1 << " and " << root2 << endl;
    }
    else if (disc == 0)
        cout << "Roots are real and equal: " << -b / (2 * a) << endl;
    else
        cout << "Roots are imaginary" << endl;
    return 0;
}
