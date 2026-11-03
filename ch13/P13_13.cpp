// P13.13: Bubble sort with a comparison function
#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size, bool (*inOrder)(int, int));
bool ascending(int a, int b);
bool descending(int a, int b);
void show(const int *arr, int size);

int main()
{
    int a[8] = {34, 7, 89, 12, 56, 3, 71, 45};

    bubbleSort(a, 8, ascending);
    cout << "Ascending:  "; show(a, 8);

    bubbleSort(a, 8, descending);
    cout << "Descending: "; show(a, 8);
    return 0;
}

void bubbleSort(int *arr, int size, bool (*inOrder)(int, int))
{
    for (int pass = 1; pass < size; pass++)
        for (int i = 0; i < size - pass; i++)
            if (!inOrder(arr[i], arr[i + 1]))     // the function decides the order
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
}

bool ascending(int a, int b)  { return a <= b; }
bool descending(int a, int b) { return a >= b; }

void show(const int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
