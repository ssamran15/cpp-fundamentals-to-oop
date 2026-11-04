// P25.7: v * 3 and 3 * v for a Vector2D
#include <iostream>
using namespace std;

class Vector2D
{
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D operator*(double k) const              // v * 3
    {
        return Vector2D(x * k, y * k);
    }

    friend Vector2D operator*(double k, const Vector2D &v);    // 3 * v
    friend ostream &operator<<(ostream &out, const Vector2D &v);
};

Vector2D operator*(double k, const Vector2D &v)
{
    return v * k;                                   // reuse the member version
}

ostream &operator<<(ostream &out, const Vector2D &v)
{
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

int main()
{
    Vector2D v(2, -1.5);
    cout << "v     = " << v << endl;
    cout << "v * 3 = " << v * 3 << endl;
    cout << "3 * v = " << 3 * v << endl;
    cout << "0.5 * v * 4 = " << 0.5 * v * 4 << endl;
    return 0;
}
