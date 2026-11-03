// P14.4: Removing an element by making a smaller array
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "How many numbers? ";
    cin >> n;

    int *a = new int[n];
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int pos;
    cout << "Position to remove (1 to " << n << "): ";
    cin >> pos;
    if (pos < 1 || pos > n)
    {
        cout << "Invalid position" << endl;
        delete[] a;
        return 1;
    }

    int *smaller = new int[n - 1];
    for (int i = 0, j = 0; i < n; i++)
        if (i != pos - 1)               // copy everything except the removed element
            smaller[j++] = a[i];

    delete[] a;                         // free the old array
    a = smaller;                        // and use the new one
    n--;

    cout << "After removing: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    delete[] a;
    return 0;
}
