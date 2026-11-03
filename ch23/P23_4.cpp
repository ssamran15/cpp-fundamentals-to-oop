// P23.4: 2 x 2 matrices with +, * and ==
#include <iostream>
using namespace std;

class Matrix2
{
private:
    int a[2][2];

public:
    Matrix2(int p = 0, int q = 0, int r = 0, int s = 0)
    {
        a[0][0] = p; a[0][1] = q;
        a[1][0] = r; a[1][1] = s;
    }

    Matrix2 operator+(const Matrix2 &m) const
    {
        Matrix2 result;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.a[i][j] = a[i][j] + m.a[i][j];
        return result;
    }

    Matrix2 operator*(const Matrix2 &m) const
    {
        Matrix2 result;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    result.a[i][j] += a[i][k] * m.a[k][j];
        return result;
    }

    bool operator==(const Matrix2 &m) const
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                if (a[i][j] != m.a[i][j])
                    return false;
        return true;
    }

    void show() const
    {
        cout << "  [" << a[0][0] << " " << a[0][1] << "]" << endl;
        cout << "  [" << a[1][0] << " " << a[1][1] << "]" << endl;
    }
};

int main()
{
    Matrix2 x(1, 2, 3, 4), y(5, 6, 7, 8), identity(1, 0, 0, 1);

    cout << "x + y:" << endl; (x + y).show();
    cout << "x * y:" << endl; (x * y).show();
    cout << "y * x:" << endl; (y * x).show();
    cout << "x * y == y * x? " << (x * y == y * x ? "yes" : "no") << endl;
    cout << "x * identity == x? " << (x * identity == x ? "yes" : "no") << endl;
    return 0;
}
