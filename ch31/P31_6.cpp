// P31.6: A Matrix class template with non-type parameters
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T, int ROWS, int COLS>
class Matrix
{
private:
    T a[ROWS][COLS];

public:
    Matrix()
    {
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                a[i][j] = T();
    }

    void read()
    {
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                cin >> a[i][j];
    }

    void print() const
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
                cout << setw(8) << a[i][j];
            cout << endl;
        }
    }

    Matrix add(const Matrix &m) const     // the same ROWS and COLS only
    {
        Matrix result;
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                result.a[i][j] = a[i][j] + m.a[i][j];
        return result;
    }
};

int main()
{
    Matrix<int, 2, 3> x, y;
    cout << "Two 2 x 3 int matrices:" << endl;
    x.read();
    y.read();
    cout << "Sum:" << endl;
    x.add(y).print();

    Matrix<double, 2, 2> p, q;
    cout << "Two 2 x 2 double matrices:" << endl;
    p.read();
    q.read();
    cout << "Sum:" << endl;
    p.add(q).print();
    return 0;
}
