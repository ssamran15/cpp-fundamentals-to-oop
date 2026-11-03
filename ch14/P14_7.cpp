// P14.7: Pascal's triangle in a jagged dynamic array
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout << "Number of rows: ";
    cin >> n;

    int **p = new int*[n];             // one pointer for each row
    for (int i = 0; i < n; i++)
    {
        p[i] = new int[i + 1];         // row i has i + 1 elements
        p[i][0] = 1;
        p[i][i] = 1;
        for (int j = 1; j < i; j++)
            p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << setw(5) << p[i][j];
        cout << endl;
    }

    for (int i = 0; i < n; i++)        // free each row, then the row pointers
        delete[] p[i];
    delete[] p;
    return 0;
}
