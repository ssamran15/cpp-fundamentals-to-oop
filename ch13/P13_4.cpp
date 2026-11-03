// P13.4: Even numbers with a moving pointer
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int a[SIZE];
    int *end = a + SIZE;               // one past the last element

    cout << "Enter " << SIZE << " numbers: ";
    for (int *p = a; p < end; p++)
        cin >> *p;

    cout << "Even numbers: ";
    for (int *p = a; p < end; p++)
        if (*p % 2 == 0)
            cout << *p << " ";
    cout << endl;
    return 0;
}
