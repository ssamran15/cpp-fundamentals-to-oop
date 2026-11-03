// P21.5: Counting the Car objects that exist
#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string model;
    static int count;

public:
    Car(string m) : model(m)
    {
        count++;
    }

    ~Car()
    {
        count--;
    }

    static void showCount()
    {
        cout << "Cars now: " << count << endl;
    }
};

int Car::count = 0;

int main()
{
    Car::showCount();                   // can be called before any car exists

    Car a("Sedan");
    Car b("Hatchback");
    cout << "After creating a and b: ";
    Car::showCount();

    {
        Car c("Jeep");
        cout << "Inside the block: ";
        Car::showCount();
    }                                   // c is destroyed here
    cout << "After the block: ";
    Car::showCount();

    Car *p = new Car("Van");
    cout << "After new: ";
    Car::showCount();

    delete p;
    cout << "After delete: ";
    Car::showCount();
    return 0;
}
