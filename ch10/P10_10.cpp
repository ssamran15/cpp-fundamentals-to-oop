// P10.10: Merging two sorted arrays
#include <iostream>
using namespace std;

void mergeArrays(const int a[], const int b[], int c[], int size);

int main()
{
    int a[5] = {2, 9, 14, 30, 41};
    int b[5] = {5, 9, 11, 27, 50};
    int c[10];

    mergeArrays(a, b, c, 5);

    cout << "Merged: ";
    for (int i = 0; i < 10; i++)
        cout << c[i] << " ";
    cout << endl;
    return 0;
}

// a and b each have size elements; c must have room for 2 * size
void mergeArrays(const int a[], const int b[], int c[], int size)
{
    int i = 0, j = 0, k = 0;
    while (i < size && j < size)
    {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < size)            // copy what is left of a
        c[k++] = a[i++];
    while (j < size)            // copy what is left of b
        c[k++] = b[j++];
}
