// P17.7: A CeilingFan class with speed 0 to 5
#include <iostream>
using namespace std;

class CeilingFan
{
private:
    int speed;

public:
    void faster()
    {
        if (speed < 5)
            speed++;
    }

    void slower()
    {
        if (speed > 0)
            speed--;
    }

    void turnOff()
    {
        speed = 0;
    }

    void show()
    {
        if (speed == 0)
            cout << "Fan is off" << endl;
        else
            cout << "Fan speed: " << speed << endl;
    }
};

int main()
{
    CeilingFan fan;
    fan.turnOff();                      // a known starting state
    fan.show();

    for (int i = 1; i <= 7; i++)        // 7 presses, but the speed stops at 5
        fan.faster();
    fan.show();

    fan.slower();
    fan.slower();
    fan.show();

    fan.turnOff();
    fan.slower();                       // already 0: nothing happens
    fan.show();
    return 0;
}
