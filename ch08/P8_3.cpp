// P8.3: Right triangle of stars
#include <iostream>
using namespace std;

void printPattern(int rows);

int main()
{
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;
    printPattern(rows);
    return 0;
}

void printPattern(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }
}
