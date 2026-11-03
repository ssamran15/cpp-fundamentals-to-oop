// P11.4: Sum, difference and product of two matrices
#include <iostream>
#include <iomanip>
using namespace std;

const int N = 3;

void inputMatrix(int m[][N]);
void printMatrix(const int m[][N]);

int main()
{
    int a[N][N], b[N][N], sum[N][N], diff[N][N], prod[N][N];

    cout << "Matrix A:" << endl;
    inputMatrix(a);
    cout << "Matrix B:" << endl;
    inputMatrix(b);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
            diff[i][j] = a[i][j] - b[i][j];
            prod[i][j] = 0;
            for (int k = 0; k < N; k++)
                prod[i][j] += a[i][k] * b[k][j];
        }
    }

    cout << endl << "A + B" << endl;
    printMatrix(sum);
    cout << "A - B" << endl;
    printMatrix(diff);
    cout << "A x B" << endl;
    printMatrix(prod);
    return 0;
}

void inputMatrix(int m[][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> m[i][j];
}

void printMatrix(const int m[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << setw(6) << m[i][j];
        cout << endl;
    }
}
