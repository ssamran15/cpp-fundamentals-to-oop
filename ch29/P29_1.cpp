// P29.1: SmartPhone derived from Phone and Camera
#include <iostream>
#include <string>
using namespace std;

class Phone
{
protected:
    string number, network;

public:
    Phone(string n, string net) : number(n), network(net)
    {
        cout << "[Phone constructor]" << endl;
    }
    void showPhone() const { cout << "Number: " << number << " on " << network << endl; }
};

class Camera
{
protected:
    double megapixels;

public:
    Camera(double mp) : megapixels(mp)
    {
        cout << "[Camera constructor]" << endl;
    }
    void showCamera() const { cout << "Camera: " << megapixels << " MP" << endl; }
};

class SmartPhone : public Phone, public Camera
{
private:
    int storageGB;

public:
    // base classes are built in the order they are listed in the class
    // header (Phone, then Camera), so the initializer list follows that order
    SmartPhone(string n, string net, double mp, int gb)
        : Phone(n, net), Camera(mp), storageGB(gb)
    {
        cout << "[SmartPhone constructor]" << endl;
    }

    void show() const
    {
        showPhone();
        showCamera();
        cout << "Storage: " << storageGB << " GB" << endl;
    }
};

int main()
{
    SmartPhone s("0300-1112223", "CityNet", 48, 128);
    cout << endl;
    s.show();
    return 0;
}
