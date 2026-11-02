// P6.3: The larger of two numbers
#include <iostream>
using namespace std;

int main()
{
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    if (a > b)
        cout << "Larger number: " << a << endl;
    else if (b > a)
        cout << "Larger number: " << b << endl;
    else
        cout << "Both numbers are equal" << endl;
    return 0;
}
