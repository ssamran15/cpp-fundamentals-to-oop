// P11.2: Largest and smallest element with position
#include <iostream>
using namespace std;

int main()
{
    const int N = 4;
    int m[N][N];

    cout << "Enter a 4 x 4 matrix row by row:" << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> m[i][j];

    int maxRow = 0, maxCol = 0, minRow = 0, minCol = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (m[i][j] > m[maxRow][maxCol])
            {
                maxRow = i;
                maxCol = j;
            }
            if (m[i][j] < m[minRow][minCol])
            {
                minRow = i;
                minCol = j;
            }
        }
    }

    cout << "Largest = " << m[maxRow][maxCol] << " at row " << maxRow + 1
         << ", column " << maxCol + 1 << endl;
    cout << "Smallest = " << m[minRow][minCol] << " at row " << minRow + 1
         << ", column " << minCol + 1 << endl;
    return 0;
}
