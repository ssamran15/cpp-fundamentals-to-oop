// P18.6: A Cylinder class with inline member functions
#include <iostream>
using namespace std;

class Cylinder
{
private:
    double radius;
    double height;

public:
    void set(double r, double h) { radius = r; height = h; }

    // short functions defined inside the class are inline automatically
    double volume() { return 3.14159 * radius * radius * height; }
    double surfaceArea();
};

// a function defined outside the class is inline only if marked so
inline double Cylinder::surfaceArea()
{
    return 2 * 3.14159 * radius * (radius + height);
}

int main()
{
    Cylinder c;
    double r, h;
    cout << "Radius and height: ";
    cin >> r >> h;
    c.set(r, h);

    cout << "Volume = " << c.volume() << endl;
    cout << "Surface area = " << c.surfaceArea() << endl;
    return 0;
}
