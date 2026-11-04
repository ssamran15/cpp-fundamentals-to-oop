// P27.5: An abstract Shape3D with Cube, Sphere and Cylinder
#include <iostream>
#include <string>
using namespace std;

const double PI = 3.14159;

class Shape3D
{
public:
    virtual ~Shape3D() {}
    virtual string name() const = 0;
    virtual double volume() const = 0;
    virtual double surfaceArea() const = 0;
};

class Cube : public Shape3D
{
private:
    double side;

public:
    Cube(double s) : side(s) {}
    string name() const override { return "Cube"; }
    double volume() const override { return side * side * side; }
    double surfaceArea() const override { return 6 * side * side; }
};

class Sphere : public Shape3D
{
private:
    double r;

public:
    Sphere(double radius) : r(radius) {}
    string name() const override { return "Sphere"; }
    double volume() const override { return 4.0 / 3 * PI * r * r * r; }
    double surfaceArea() const override { return 4 * PI * r * r; }
};

class Cylinder : public Shape3D
{
private:
    double r, h;

public:
    Cylinder(double radius, double height) : r(radius), h(height) {}
    string name() const override { return "Cylinder"; }
    double volume() const override { return PI * r * r * h; }
    double surfaceArea() const override { return 2 * PI * r * (r + h); }
};

int main()
{
    double side, radius, cr, ch;
    cout << "Side of the cube: ";
    cin >> side;
    cout << "Radius of the sphere: ";
    cin >> radius;
    cout << "Radius and height of the cylinder: ";
    cin >> cr >> ch;

    Shape3D *shapes[3];
    shapes[0] = new Cube(side);
    shapes[1] = new Sphere(radius);
    shapes[2] = new Cylinder(cr, ch);

    cout << endl;
    for (int i = 0; i < 3; i++)
        cout << shapes[i]->name() << ": volume " << shapes[i]->volume()
             << ", surface area " << shapes[i]->surfaceArea() << endl;

    for (int i = 0; i < 3; i++)
        delete shapes[i];               // the virtual destructor makes this safe
    // Shape3D s;                       // error: Shape3D is abstract
    return 0;
}
