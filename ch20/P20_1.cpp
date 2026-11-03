// P20.1: Adding two Distance objects with a non-member function
#include <iostream>
using namespace std;

class Distance
{
private:
    int feet, inches;

public:
    Distance(int f = 0, int i = 0)
    {
        feet = f + i / 12;
        inches = i % 12;
    }

    int getFeet() const { return feet; }        // const: safe to call on a const object
    int getInches() const { return inches; }

    void show() const
    {
        cout << feet << "' " << inches << "\"";
    }
};

Distance addDistances(const Distance &a, const Distance &b)
{
    // the constructor carries extra inches into feet
    return Distance(a.getFeet() + b.getFeet(), a.getInches() + b.getInches());
}

int main()
{
    Distance d1(5, 9), d2(3, 7);
    Distance total = addDistances(d1, d2);

    d1.show();
    cout << " + ";
    d2.show();
    cout << " = ";
    total.show();
    cout << endl;
    return 0;
}
