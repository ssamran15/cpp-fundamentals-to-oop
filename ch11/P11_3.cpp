// P11.3: Symmetric matrix check
#include <iostream>
using namespace std;

int main()
{
    const int MAX = 10;
    int m[MAX][MAX];
    int n;

    cout << "Size of the square matrix (1 to 10): ";
    cin >> n;
    cout << "Enter the matrix row by row:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];

    bool symmetric = true;
    for (int i = 0; i < n && symmetric; i++)
        for (int j = i + 1; j < n; j++)
            if (m[i][j] != m[j][i])
            {
                symmetric = false;
                break;
            }

    if (symmetric)
        cout << "The matrix is symmetric" << endl;
    else
        cout << "The matrix is not symmetric" << endl;
    return 0;
}
