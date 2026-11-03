// P13.5: Reversing an array with two pointers
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 8;
    int a[SIZE];

    cout << "Enter " << SIZE << " numbers: ";
    for (int *p = a; p < a + SIZE; p++)
        cin >> *p;

    int *left = a;                     // first element
    int *right = a + SIZE - 1;         // last element
    while (left < right)
    {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }

    cout << "Reversed: ";
    for (int *p = a; p < a + SIZE; p++)
        cout << *p << " ";
    cout << endl;
    return 0;
}
