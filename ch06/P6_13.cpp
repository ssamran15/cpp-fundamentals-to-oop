// P6.13: Using the conditional operator only
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int larger = (a > b) ? a : b;
    cout << "Larger number: " << larger << endl;

    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << n << " is " << (n % 2 == 0 ? "even" : "odd") << endl;
    return 0;
}
