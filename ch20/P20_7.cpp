// P20.7: A Matrix class that returns its transpose
#include <iostream>
#include <iomanip>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    int **data;

    void allocate()
    {
        data = new int*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new int[cols];
    }

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        allocate();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = 0;
    }

    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols)
    {
        allocate();                                 // its own rows
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }

    void input()
    {
        cout << "Enter a " << rows << " x " << cols << " matrix:" << endl;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
    }

    Matrix transpose()
    {
        Matrix t(cols, rows);                       // rows and columns swap
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                t.data[j][i] = data[i][j];
        return t;
    }

    void show()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                cout << setw(5) << data[i][j];
            cout << endl;
        }
    }
};

int main()
{
    Matrix m(2, 3);
    m.input();

    Matrix t = m.transpose();
    cout << "Matrix:" << endl;
    m.show();
    cout << "Transpose:" << endl;
    t.show();

    Matrix copy(m);                                 // a deep copy
    cout << "Copy of the matrix:" << endl;
    copy.show();
    return 0;
}
