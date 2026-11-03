// P13.3: Smallest and largest with pointer notation
#include <iostream>
using namespace std;

void minMax(const int *arr, int size, int *mn, int *mx);

int main()
{
    const int SIZE = 6;
    int a[SIZE];
    cout << "Enter " << SIZE << " numbers: ";
    for (int i = 0; i < SIZE; i++)
        cin >> *(a + i);

    int smallest, largest;
    minMax(a, SIZE, &smallest, &largest);
    cout << "Smallest = " << smallest << endl;
    cout << "Largest = " << largest << endl;
    return 0;
}

void minMax(const int *arr, int size, int *mn, int *mx)
{
    *mn = *arr;
    *mx = *arr;
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) < *mn) *mn = *(arr + i);
        if (*(arr + i) > *mx) *mx = *(arr + i);
    }
}
