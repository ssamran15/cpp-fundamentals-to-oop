// P14.10: Create, fill and free a dynamic array
#include <iostream>
using namespace std;

int* createArray(int n);
void fillArray(int *a, int n);
void freeArray(int *&a);

int main()
{
    int n;
    cout << "Size of the array: ";
    cin >> n;

    int *a = createArray(n);
    fillArray(a, n);

    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    freeArray(a);
    if (a == nullptr)
        cout << "Memory freed; the pointer is now nullptr" << endl;
    return 0;
}

int* createArray(int n)
{
    return new int[n];
}

void fillArray(int *a, int n)
{
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void freeArray(int *&a)        // a reference to the caller's pointer
{
    delete[] a;
    a = nullptr;
}
