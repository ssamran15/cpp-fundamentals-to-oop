// P26.3: Car and Truck derived from Vehicle
#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string regNo, company;
    int year;

public:
    Vehicle(string r, string c, int y) : regNo(r), company(c), year(y) {}

    void show() const
    {
        cout << regNo << ", " << company << ", model " << year;
    }
};

class Car : public Vehicle
{
private:
    int seats;

public:
    Car(string r, string c, int y, int s) : Vehicle(r, c, y), seats(s) {}

    void show() const
    {
        cout << "Car: ";
        Vehicle::show();
        cout << ", " << seats << " seats" << endl;
    }
};

class Truck : public Vehicle
{
private:
    double tons;

public:
    Truck(string r, string c, int y, double t) : Vehicle(r, c, y), tons(t) {}

    void show() const
    {
        cout << "Truck: ";
        Vehicle::show();
        cout << ", load " << tons << " tons" << endl;
    }
};

int main()
{
    Car car("OKR-2471", "Okara Motors", 2022, 5);
    Truck truck("LHR-8820", "Valley Haulage", 2019, 12.5);
    car.show();
    truck.show();
    return 0;
}
