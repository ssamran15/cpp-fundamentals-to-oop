// P28.1: The size cost of virtual functions
#include <iostream>
using namespace std;

class NoVirtual
{
    double d;
    int i;

public:
    NoVirtual() : d(0), i(0) {}
    void f() {}
};

class OneVirtual
{
    double d;
    int i;

public:
    OneVirtual() : d(0), i(0) {}
    virtual ~OneVirtual() {}
};

class FiveVirtual
{
    double d;
    int i;

public:
    FiveVirtual() : d(0), i(0) {}
    virtual ~FiveVirtual() {}
    virtual void a() {}
    virtual void b() {}
    virtual void c() {}
    virtual void e() {}
};

int main()
{
    cout << "sizeof(double) + sizeof(int) = " << sizeof(double) + sizeof(int) << endl;
    cout << "sizeof(void *)               = " << sizeof(void *) << endl;
    cout << "No virtual function    : " << sizeof(NoVirtual) << " bytes" << endl;
    cout << "One virtual function   : " << sizeof(OneVirtual) << " bytes" << endl;
    cout << "Five virtual functions : " << sizeof(FiveVirtual) << " bytes" << endl;
    return 0;
}
