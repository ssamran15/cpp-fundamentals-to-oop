// P10.14: Selection sort and binary search
#include <iostream>
using namespace std;

void selectionSort(int a[], int size);
int binarySearch(const int a[], int size, int key);

int main()
{
    const int SIZE = 10;
    int marks[SIZE];

    cout << "Enter the marks of " << SIZE << " students: ";
    for (int i = 0; i < SIZE; i++)
        cin >> marks[i];

    selectionSort(marks, SIZE);
    cout << "Sorted marks: ";
    for (int i = 0; i < SIZE; i++)
        cout << marks[i] << " ";
    cout << endl;

    int key;
    cout << "Mark to search: ";
    cin >> key;
    int pos = binarySearch(marks, SIZE, key);
    if (pos == -1)
        cout << key << " was not obtained by any student" << endl;
    else
        cout << key << " was obtained (position " << pos + 1 << " in the sorted list)" << endl;
    return 0;
}

void selectionSort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;
        int temp = a[i];
        a[i] = a[minPos];
        a[minPos] = temp;
    }
}

// returns the index of key, or -1 if it is not in the array
int binarySearch(const int a[], int size, int key)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
