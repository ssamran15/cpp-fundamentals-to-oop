// P5.12: Roots of a quadratic equation (real roots)
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;

    double d = sqrt(b * b - 4 * a * c);
    double root1 = (-b + d) / (2 * a);
    double root2 = (-b - d) / (2 * a);

    cout << "Root 1 = " << root1 << endl;
    cout << "Root 2 = " << root2 << endl;
    return 0;
}
