// P10.12: Bubble sort in descending order
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int a[SIZE];

    cout << "Enter " << SIZE << " numbers: ";
    for (int i = 0; i < SIZE; i++)
        cin >> a[i];

    for (int pass = 1; pass < SIZE; pass++)
    {
        for (int i = 0; i < SIZE - pass; i++)
        {
            if (a[i] < a[i + 1])        // < instead of > gives descending order
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }

    cout << "Descending order: ";
    for (int i = 0; i < SIZE; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
