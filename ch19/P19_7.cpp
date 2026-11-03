// P19.7: A Matrix class with a dynamic 2D array
#include <iostream>
#include <iomanip>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    int **data;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new int[cols];
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)      // each row first,
            delete[] data[i];
        delete[] data;                      // then the array of row pointers
    }

    void input()
    {
        cout << "Enter a " << rows << " x " << cols << " matrix:" << endl;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
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
    int r, c;
    cout << "Rows and columns: ";
    cin >> r >> c;

    Matrix m(r, c);
    m.input();
    cout << "The matrix:" << endl;
    m.show();
    return 0;
}
