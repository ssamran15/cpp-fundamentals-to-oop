// P25.4: An Inspector friend class checks the buses
#include <iostream>
#include <string>
using namespace std;

class Bus
{
private:
    string route;
    int seats, passengers;

public:
    Bus(string r, int s, int p) : route(r), seats(s), passengers(p) {}
    friend class Inspector;         // every member of Inspector may see the private data
};

class Inspector
{
public:
    void check(const Bus buses[], int n) const
    {
        int overloaded = 0;
        for (int i = 0; i < n; i++)
        {
            cout << buses[i].route << ": " << buses[i].passengers << " passengers, "
                 << buses[i].seats << " seats";
            if (buses[i].passengers > buses[i].seats)
            {
                cout << "  OVERLOADED by " << buses[i].passengers - buses[i].seats;
                overloaded++;
            }
            cout << endl;
        }
        cout << overloaded << " of " << n << " buses are overloaded" << endl;
    }
};

int main()
{
    Bus fleet[4] = { Bus("Okara - Lahore", 45, 52), Bus("Okara - Sahiwal", 45, 40),
                     Bus("Okara - Faisalabad", 30, 30), Bus("Okara - Depalpur", 30, 37) };
    Inspector inspector;
    inspector.check(fleet, 4);
    return 0;
}
