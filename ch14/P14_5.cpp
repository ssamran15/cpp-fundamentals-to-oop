// P14.5: A dynamic array that grows by doubling
#include <iostream>
using namespace std;

int main()
{
    int capacity = 2, count = 0;
    int *a = new int[capacity];
    int x;

    cout << "Enter numbers (a negative number to stop): ";
    cin >> x;
    while (x >= 0)
    {
        if (count == capacity)                   // full: make it twice as big
        {
            int *bigger = new int[capacity * 2];
            for (int i = 0; i < count; i++)
                bigger[i] = a[i];
            delete[] a;
            a = bigger;
            capacity *= 2;
            cout << "  (capacity grew to " << capacity << ")" << endl;
        }
        a[count++] = x;
        cin >> x;
    }

    for (int pass = 1; pass < count; pass++)     // bubble sort
        for (int i = 0; i < count - pass; i++)
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }

    cout << count << " numbers in sorted order: ";
    for (int i = 0; i < count; i++)
        cout << a[i] << " ";
    cout << endl;

    delete[] a;
    return 0;
}
