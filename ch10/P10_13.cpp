// P10.13: Bubble sort that stops early
#include <iostream>
using namespace std;

int bubbleSort(int a[], int size);
void printArray(const int a[], int size);

int main()
{
    int sorted[8]   = {3, 7, 12, 18, 25, 31, 40, 52};
    int unsorted[8] = {40, 7, 52, 3, 25, 18, 31, 12};

    int passes = bubbleSort(sorted, 8);
    cout << "Already sorted array: ";
    printArray(sorted, 8);
    cout << "Passes used: " << passes << endl << endl;

    passes = bubbleSort(unsorted, 8);
    cout << "Unsorted array after sorting: ";
    printArray(unsorted, 8);
    cout << "Passes used: " << passes << endl;
    return 0;
}

// sorts in ascending order and returns the number of passes made
int bubbleSort(int a[], int size)
{
    int passes = 0;
    for (int pass = 1; pass < size; pass++)
    {
        passes++;
        bool swapped = false;
        for (int i = 0; i < size - pass; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)           // no swaps: the array is already in order
            break;
    }
    return passes;
}

void printArray(const int a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}
