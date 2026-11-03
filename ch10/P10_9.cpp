// P10.9: Is the array sorted?
#include <iostream>
using namespace std;

bool isSorted(const int arr[], int size);

int main()
{
    int a[6] = {3, 8, 12, 12, 20, 41};
    int b[6] = {3, 8, 15, 12, 20, 41};

    cout << "Array a is " << (isSorted(a, 6) ? "sorted" : "not sorted") << endl;
    cout << "Array b is " << (isSorted(b, 6) ? "sorted" : "not sorted") << endl;
    return 0;
}

bool isSorted(const int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;       // one pair out of order is enough
    return true;
}
