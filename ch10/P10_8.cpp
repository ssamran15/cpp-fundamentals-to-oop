// P10.8: Counting a value in an array
#include <iostream>
using namespace std;

int countValue(const int arr[], int size, int value);

int main()
{
    int a[12] = {4, 7, 4, 9, 1, 4, 7, 3, 4, 8, 7, 2};
    int value;

    cout << "Array: ";
    for (int i = 0; i < 12; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "Value to count: ";
    cin >> value;
    cout << value << " appears " << countValue(a, 12, value) << " time(s)" << endl;
    return 0;
}

int countValue(const int arr[], int size, int value)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
            count++;
    return count;
}
