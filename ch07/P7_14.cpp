// P7.14: Four patterns
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    // Pattern 1: numbers
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= row; col++)
            cout << col << " ";
        cout << endl;
    }
    cout << endl;

    // Pattern 2: stars, getting shorter
    for (int row = n; row >= 1; row--)
    {
        for (int col = 1; col <= row; col++)
            cout << "* ";
        cout << endl;
    }
    cout << endl;

    // Pattern 3: pyramid of stars
    for (int row = 1; row <= n; row++)
    {
        for (int s = 1; s <= n - row; s++)
            cout << " ";
        for (int col = 1; col <= row; col++)
            cout << "* ";
        cout << endl;
    }
    cout << endl;

    // Pattern 4: pyramid of row numbers
    for (int row = 1; row <= n; row++)
    {
        for (int s = 1; s <= n - row; s++)
            cout << " ";
        for (int col = 1; col <= row; col++)
            cout << row << " ";
        cout << endl;
    }
    return 0;
}
