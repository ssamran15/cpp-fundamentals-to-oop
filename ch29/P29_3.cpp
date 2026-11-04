// P29.3: Virtual base classes in an AmphibiousVehicle
#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string regNo;
    int speed;

public:
    Vehicle(string r, int s) : regNo(r), speed(s)
    {
        cout << "[Vehicle constructor]" << endl;
    }
    void setSpeed(int s) { speed = s; }
};

class LandVehicle : virtual public Vehicle
{
protected:
    int wheels;

public:
    LandVehicle(string r, int s, int w) : Vehicle(r, s), wheels(w) {}
};

class WaterVehicle : virtual public Vehicle
{
protected:
    double draught;             // metres below the water line

public:
    WaterVehicle(string r, int s, double d) : Vehicle(r, s), draught(d) {}
};

class AmphibiousVehicle : public LandVehicle, public WaterVehicle
{
public:
    // the most derived class constructs the shared virtual base itself
    AmphibiousVehicle(string r, int s, int w, double d)
        : Vehicle(r, s), LandVehicle(r, s, w), WaterVehicle(r, s, d) {}

    void show() const
    {
        // no ambiguity: there is only one regNo and one speed
        cout << regNo << ": " << speed << " km/h, " << wheels
             << " wheels, draught " << draught << " m" << endl;
    }

    void addresses() const
    {
        const Vehicle *viaLand = static_cast<const LandVehicle *>(this);
        const Vehicle *viaWater = static_cast<const WaterVehicle *>(this);
        cout << "Vehicle part reached through LandVehicle and WaterVehicle is "
             << (viaLand == viaWater ? "the same object" : "two different objects") << endl;
    }
};

int main()
{
    AmphibiousVehicle a("AMP-07", 40, 6, 0.8);
    a.show();
    a.addresses();

    a.LandVehicle::setSpeed(55);        // change it through one path...
    a.show();                           // ...and the single Vehicle part shows it
    return 0;
}
