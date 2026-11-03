// P16.11: Largest of any number of arguments
#include <iostream>
#include <cstdarg>
using namespace std;

int largest(int count, ...);

int main()
{
    cout << "Largest of 3: " << largest(3, 12, 45, 7) << endl;
    cout << "Largest of 5: " << largest(5, 18, -4, 66, 23, 50) << endl;
    cout << "Largest of 7: " << largest(7, 5, 91, 14, 88, 3, 70, 42) << endl;
    return 0;
}

int largest(int count, ...)
{
    va_list args;
    va_start(args, count);          // start after the last named parameter

    int big = va_arg(args, int);    // the first number
    for (int i = 1; i < count; i++)
    {
        int x = va_arg(args, int);
        if (x > big)
            big = x;
    }
    va_end(args);
    return big;
}
