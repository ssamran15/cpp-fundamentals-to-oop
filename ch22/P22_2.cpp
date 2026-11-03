// P22.2: A Student composed of an Address
#include <iostream>
#include <string>
using namespace std;

class Address
{
private:
    string house, street, city;

public:
    Address(string h, string s, string c) : house(h), street(s), city(c) {}

    void show() const
    {
        cout << "House " << house << ", " << street << ", " << city;
    }
};

class Student
{
private:
    string name;
    Address address;            // composition

public:
    // the address details are passed on to Address's constructor
    Student(string n, string h, string s, string c) : name(n), address(h, s, c) {}

    void show() const
    {
        cout << name << ": ";
        address.show();
        cout << endl;
    }
};

int main()
{
    Student s1("Ali Raza", "12-B", "Canal Road", "Okara");
    Student s2("Sana Tariq", "45", "Mall Road", "Lahore");
    s1.show();
    s2.show();
    return 0;
}
