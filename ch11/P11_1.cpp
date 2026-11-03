// P11.1: Row, column and diagonal sums
#include <iostream>
using namespace std;

int main()
{
    const int N = 3;
    int m[N][N];

    cout << "Enter a 3 x 3 matrix row by row:" << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> m[i][j];

    for (int i = 0; i < N; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < N; j++)
            rowSum += m[i][j];
        cout << "Sum of row " << i + 1 << " = " << rowSum << endl;
    }

    for (int j = 0; j < N; j++)
    {
        int colSum = 0;
        for (int i = 0; i < N; i++)
            colSum += m[i][j];
        cout << "Sum of column " << j + 1 << " = " << colSum << endl;
    }

    int mainDiag = 0, otherDiag = 0;
    for (int i = 0; i < N; i++)
    {
        mainDiag += m[i][i];
        otherDiag += m[i][N - 1 - i];
    }
    cout << "Sum of main diagonal = " << mainDiag << endl;
    cout << "Sum of other diagonal = " << otherDiag << endl;
    return 0;
}
