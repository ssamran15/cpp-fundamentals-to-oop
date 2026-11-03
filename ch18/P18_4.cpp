// P18.4: A Distance class in feet and inches
#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inches;

public:
    void setDistance(int f, int i)
    {
        feet = f + i / 12;              // move whole feet out of the inches
        inches = i % 12;
    }

    void add(Distance &d)
    {
        setDistance(feet + d.feet, inches + d.inches);
    }

    void show()
    {
        cout << feet << "' " << inches << "\"" << endl;
    }
};

int main()
{
    Distance d1, d2;
    int f, i;

    cout << "First distance (feet inches): ";
    cin >> f >> i;
    d1.setDistance(f, i);
    cout << "Stored as ";
    d1.show();

    cout << "Second distance (feet inches): ";
    cin >> f >> i;
    d2.setDistance(f, i);
    cout << "Stored as ";
    d2.show();

    d1.add(d2);
    cout << "Sum: ";
    d1.show();
    return 0;
}
