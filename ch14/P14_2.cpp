// P14.2: A reversed copy on the heap
#include <iostream>
using namespace std;

int* reversedCopy(const int *a, int n);
void show(const int *a, int n);

int main()
{
    int n;
    cout << "How many numbers? ";
    cin >> n;

    int *original = new int[n];
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++)
        cin >> original[i];

    int *reversed = reversedCopy(original, n);
    cout << "Original: "; show(original, n);
    cout << "Reversed: "; show(reversed, n);

    delete[] original;
    delete[] reversed;       // main owns the array the function created
    return 0;
}

int* reversedCopy(const int *a, int n)
{
    int *r = new int[n];
    for (int i = 0; i < n; i++)
        r[i] = a[n - 1 - i];
    return r;
}

void show(const int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
