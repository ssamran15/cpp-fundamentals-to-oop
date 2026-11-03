// P15.11: Bubble sort with a DEBUG switch
#include <iostream>
using namespace std;

#define DEBUG          // remove this line to turn off the pass-by-pass output

int main()
{
    const int SIZE = 6;
    int a[SIZE] = {29, 10, 14, 37, 13, 5};

    for (int pass = 1; pass < SIZE; pass++)
    {
        for (int i = 0; i < SIZE - pass; i++)
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }

#ifdef DEBUG
        cout << "After pass " << pass << ": ";
        for (int i = 0; i < SIZE; i++)
            cout << a[i] << " ";
        cout << endl;
#endif
    }

    cout << "Sorted: ";
    for (int i = 0; i < SIZE; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
