// P10.3: Reverse order, then reversing the array itself
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int a[SIZE];

    cout << "Enter " << SIZE << " numbers: ";
    for (int i = 0; i < SIZE; i++)
        cin >> a[i];

    cout << "In reverse order: ";
    for (int i = SIZE - 1; i >= 0; i--)
        cout << a[i] << " ";
    cout << endl;

    // swap the first with the last, the second with the second last, ...
    for (int i = 0; i < SIZE / 2; i++)
    {
        int temp = a[i];
        a[i] = a[SIZE - 1 - i];
        a[SIZE - 1 - i] = temp;
    }

    cout << "Array after reversing: ";
    for (int i = 0; i < SIZE; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
