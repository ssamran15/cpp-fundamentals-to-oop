// P24.1: A Matrix with operator()(r, c) and bounds checking
#include <iostream>
#include <iomanip>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    int **data;
    int dummy;                          // returned for a bad index

    void allocate()
    {
        data = new int*[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = 0;
        }
    }

    void release()
    {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }

    bool valid(int r, int c) const
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
            return true;
        cout << "[index (" << r << ", " << c << ") out of range]" << endl;
        return false;
    }

public:
    Matrix(int r, int c) : rows(r), cols(c), dummy(0)
    {
        allocate();
    }

    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), dummy(0)
    {
        allocate();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
    }

    Matrix &operator=(const Matrix &other)
    {
        if (this == &other)
            return *this;
        release();
        rows = other.rows;
        cols = other.cols;
        allocate();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
        return *this;
    }

    ~Matrix()
    {
        release();
    }

    int &operator()(int r, int c)               // for changing an element
    {
        if (!valid(r, c))
        {
            dummy = 0;
            return dummy;
        }
        return data[r][c];
    }

    int operator()(int r, int c) const          // for reading a const Matrix
    {
        if (!valid(r, c))
            return 0;
        return data[r][c];
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

void show(const Matrix &m)                      // uses the const version
{
    for (int i = 0; i < m.getRows(); i++)
    {
        for (int j = 0; j < m.getCols(); j++)
            cout << setw(5) << m(i, j);
        cout << endl;
    }
}

int main()
{
    Matrix a(2, 3);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            a(i, j) = (i + 1) * 10 + j;         // uses the non-const version

    cout << "a:" << endl;
    show(a);

    a(5, 1) = 99;                               // caught, nothing changes

    Matrix b = a;                               // copy constructor
    b(0, 0) = -1;
    Matrix c(1, 1);
    c = a;                                      // operator=
    c(1, 2) = 500;

    cout << "a after changing b and c:" << endl;
    show(a);
    cout << "b:" << endl;
    show(b);
    cout << "c:" << endl;
    show(c);
    return 0;
}
