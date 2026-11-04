// P28.3: Installing an app on smartphones only
#include <iostream>
#include <string>
using namespace std;

class Phone
{
protected:
    string number;

public:
    Phone(string n) : number(n) {}
    virtual ~Phone() {}
    string getNumber() const { return number; }
};

class SmartPhone : public Phone
{
private:
    string apps[10];
    int count;

public:
    SmartPhone(string n) : Phone(n), count(0) {}

    void installApp(string app)
    {
        if (count < 10)
            apps[count++] = app;
        cout << number << ": installed " << app << " (" << count << " app(s) now)" << endl;
    }
};

int main()
{
    SmartPhone s1("0300-1112223"), s2("0321-4445556");
    Phone p1("0333-7778889"), p2("0345-1212343");
    Phone *phones[4] = { &s1, &p1, &s2, &p2 };

    for (int i = 0; i < 4; i++)
    {
        SmartPhone *sp = dynamic_cast<SmartPhone *>(phones[i]);
        if (sp != nullptr)
            sp->installApp("Attendance");
        else
            cout << phones[i]->getNumber() << ": an ordinary phone, no apps" << endl;
    }
    return 0;
}
