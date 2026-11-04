// P31.2: countOf and reverseArray templates
#include <iostream>
#include <string>
using namespace std;

template <typename T>
int countOf(const T a[], int n, const T &value)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == value)
            count++;
    return count;
}

template <typename T>
void reverseArray(T a[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        T temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}

template <typename T>
void printArray(const T a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int numbers[8] = { 4, 7, 4, 9, 1, 4, 7, 3 };
    char grades[6] = { 'A', 'B', 'A', 'C', 'A', 'F' };
    string days[5] = { "Mon", "Tue", "Wed", "Thu", "Fri" };

    cout << "4 appears " << countOf(numbers, 8, 4) << " times" << endl;
    cout << "'A' appears " << countOf(grades, 6, 'A') << " times" << endl;
    cout << "\"Sat\" appears " << countOf(days, 5, string("Sat")) << " times" << endl;

    reverseArray(numbers, 8);
    reverseArray(grades, 6);
    reverseArray(days, 5);
    printArray(numbers, 8);
    printArray(grades, 6);
    printArray(days, 5);
    return 0;
}
