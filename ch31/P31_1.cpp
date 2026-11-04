// P31.1: Sorting arrays of any type
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void sortArray(T a[], int n)                // bubble sort
{
    for (int pass = 1; pass < n; pass++)
        for (int i = 0; i < n - pass; i++)
            if (a[i + 1] < a[i])            // needs only < from the type
            {
                T temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
}

template <typename T>
void printArray(const T a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;
}

int main()
{
    int marks[6] = { 72, 45, 91, 58, 85, 64 };
    double prices[5] = { 650.5, 120, 1850, 160.75, 590 };
    string cities[5] = { "Okara", "Lahore", "Multan", "Faisalabad", "Sahiwal" };

    sortArray(marks, 6);
    sortArray(prices, 5);
    sortArray(cities, 5);

    printArray(marks, 6);
    printArray(prices, 5);
    printArray(cities, 5);
    return 0;
}
