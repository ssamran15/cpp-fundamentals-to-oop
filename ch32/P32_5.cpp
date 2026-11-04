// P32.5: Multiplying matrices stored in vector<vector<int>>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<vector<int>> readMatrix(int rows, int cols)
{
    vector<vector<int>> m(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> m[i][j];
    return m;
}

int main()
{
    int r1, c1, r2, c2;
    cout << "Rows and columns of A: ";
    cin >> r1 >> c1;
    cout << "Rows and columns of B: ";
    cin >> r2 >> c2;
    if (c1 != r2)
    {
        cout << "Cannot multiply: A has " << c1 << " columns but B has " << r2 << " rows" << endl;
        return 1;
    }

    cout << "Matrix A:" << endl;
    vector<vector<int>> a = readMatrix(r1, c1);
    cout << "Matrix B:" << endl;
    vector<vector<int>> b = readMatrix(r2, c2);

    vector<vector<int>> product(r1, vector<int>(c2, 0));
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                product[i][j] += a[i][k] * b[k][j];

    cout << "A x B:" << endl;
    for (const vector<int> &row : product)
    {
        for (int x : row)
            cout << setw(6) << x;
        cout << endl;
    }
    return 0;
}
