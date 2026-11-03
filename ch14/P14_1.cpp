// P14.1: Numbers above the average in a dynamic array
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "How many numbers? ";
    cin >> n;

    int *a = new int[n];
    double sum = 0;
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    double average = sum / n;
    cout << "Average = " << average << endl;
    cout << "Greater than the average: ";
    for (int i = 0; i < n; i++)
        if (a[i] > average)
            cout << a[i] << " ";
    cout << endl;

    delete[] a;
    return 0;
}
