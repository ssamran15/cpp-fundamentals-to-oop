// P13.12: Applying a function to every element
#include <iostream>
using namespace std;

void applyToAll(int *arr, int size, int (*f)(int));
void show(const int *arr, int size);
int square(int x);
int twice(int x);
int negative(int x);

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    cout << "Start:          "; show(a, 5);

    applyToAll(a, 5, square);
    cout << "After square:   "; show(a, 5);

    applyToAll(a, 5, twice);
    cout << "After double:   "; show(a, 5);

    applyToAll(a, 5, negative);
    cout << "After negative: "; show(a, 5);
    return 0;
}

void applyToAll(int *arr, int size, int (*f)(int))
{
    for (int i = 0; i < size; i++)
        arr[i] = f(arr[i]);
}

void show(const int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int square(int x)   { return x * x; }
int twice(int x)    { return 2 * x; }
int negative(int x) { return -x; }
