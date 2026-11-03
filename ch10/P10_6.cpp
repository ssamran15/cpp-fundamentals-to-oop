// P10.6: Second largest number
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int a[SIZE];

    cout << "Enter " << SIZE << " numbers: ";
    for (int i = 0; i < SIZE; i++)
        cin >> a[i];

    int largest = a[0];
    for (int i = 1; i < SIZE; i++)
        if (a[i] > largest)
            largest = a[i];

    bool found = false;
    int second = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (a[i] != largest && (!found || a[i] > second))
        {
            second = a[i];
            found = true;
        }
    }

    if (found)
        cout << "Second largest = " << second << endl;
    else
        cout << "All the numbers are equal" << endl;
    return 0;
}
