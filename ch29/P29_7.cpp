// P29.7: A House composed of Room objects
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Room
{
private:
    string name;
    double length, width;

public:
    Room() : name(""), length(0), width(0) {}
    Room(string n, double l, double w) : name(n), length(l), width(w) {}
    double area() const { return length * width; }
    string getName() const { return name; }
};

class House
{
private:
    Room rooms[6];                  // the rooms are part of the house
    int count;

public:
    House() : count(0) {}

    bool addRoom(string name, double l, double w)
    {
        if (count == 6)
            return false;
        rooms[count++] = Room(name, l, w);
        return true;
    }

    void report() const
    {
        double total = 0;
        for (int i = 0; i < count; i++)
        {
            cout << left << setw(12) << rooms[i].getName() << right << setw(8)
                 << rooms[i].area() << " sq ft" << endl;
            total += rooms[i].area();
        }
        cout << "Total covered area: " << total << " sq ft" << endl;
    }
};

int main()
{
    House h;
    int n;
    cout << "Number of rooms (up to 6): ";
    cin >> n;
    for (int i = 0; i < n && i < 6; i++)
    {
        string name;
        double l, w;
        cout << "Room " << i + 1 << " (name length width): ";
        cin >> name >> l >> w;
        h.addRoom(name, l, w);
    }
    cout << endl;
    h.report();
    return 0;
}
