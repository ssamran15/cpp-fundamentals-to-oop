// P5.8: Prefix and postfix ++ and --
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    int x = n;
    int y = x++;
    cout << "y = x++  gives y = " << y << ", x = " << x
         << "  (y gets the old value, then x increases)" << endl;

    x = n;
    y = ++x;
    cout << "y = ++x  gives y = " << y << ", x = " << x
         << "  (x increases first, then y gets the new value)" << endl;

    x = n;
    y = x--;
    cout << "y = x--  gives y = " << y << ", x = " << x
         << "  (y gets the old value, then x decreases)" << endl;

    x = n;
    y = --x;
    cout << "y = --x  gives y = " << y << ", x = " << x
         << "  (x decreases first, then y gets the new value)" << endl;
    return 0;
}
