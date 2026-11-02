// P4.5: Swapping two numbers with a third variable
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    cout << "Before swapping: a = " << a << ", b = " << b << endl;

    int temp = a;
    a = b;
    b = temp;

    cout << "After swapping : a = " << a << ", b = " << b << endl;
    return 0;
}
