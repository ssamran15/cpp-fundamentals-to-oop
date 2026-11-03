// P14.8: Adding two dynamic matrices
#include <iostream>
#include <iomanip>
using namespace std;

int** createMatrix(int rows, int cols);
void inputMatrix(int **m, int rows, int cols);
void freeMatrix(int **m, int rows);

int main()
{
    int rows, cols;
    cout << "Rows and columns: ";
    cin >> rows >> cols;

    int **a = createMatrix(rows, cols);
    int **b = createMatrix(rows, cols);
    int **sum = createMatrix(rows, cols);

    cout << "Matrix A:" << endl;
    inputMatrix(a, rows, cols);
    cout << "Matrix B:" << endl;
    inputMatrix(b, rows, cols);

    cout << "A + B:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
            cout << setw(5) << sum[i][j];
        }
        cout << endl;
    }

    freeMatrix(a, rows);
    freeMatrix(b, rows);
    freeMatrix(sum, rows);
    return 0;
}

int** createMatrix(int rows, int cols)
{
    int **m = new int*[rows];
    for (int i = 0; i < rows; i++)
        m[i] = new int[cols];
    return m;
}

void inputMatrix(int **m, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> m[i][j];
}

void freeMatrix(int **m, int rows)
{
    for (int i = 0; i < rows; i++)
        delete[] m[i];
    delete[] m;
}
