// P33.6: A Matrix whose operator+ and at() throw
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    vector<vector<int>> data;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<int>(c, 0)) {}

    int &at(int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw out_of_range("element (" + to_string(r) + ", " + to_string(c) + ") is outside a "
                               + to_string(rows) + " x " + to_string(cols) + " matrix");
        return data[r][c];
    }

    Matrix operator+(const Matrix &m) const
    {
        if (rows != m.rows || cols != m.cols)
            throw invalid_argument("cannot add a " + to_string(rows) + " x " + to_string(cols)
                                   + " matrix to a " + to_string(m.rows) + " x " + to_string(m.cols) + " matrix");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + m.data[i][j];
        return result;
    }

    void show() const
    {
        for (const vector<int> &row : data)
        {
            for (int x : row)
                cout << setw(5) << x;
            cout << endl;
        }
    }
};

int main()
{
    Matrix a(2, 2), b(2, 2), c(3, 2);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            a.at(i, j) = i + j;
            b.at(i, j) = 10 * (i + 1);
        }

    try
    {
        cout << "a + b:" << endl;
        (a + b).show();
        cout << "a + c:" << endl;
        (a + c).show();                 // throws
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    try
    {
        a.at(2, 0) = 5;                 // throws
    }
    catch (const out_of_range &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
