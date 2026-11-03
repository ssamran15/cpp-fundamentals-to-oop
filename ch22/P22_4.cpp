// P22.4: The order of construction and destruction in a Computer
#include <iostream>
using namespace std;

class Processor
{
public:
    Processor()  { cout << "  Processor built" << endl; }
    ~Processor() { cout << "  Processor removed" << endl; }
};

class Memory
{
public:
    Memory()  { cout << "  Memory built" << endl; }
    ~Memory() { cout << "  Memory removed" << endl; }
};

class Disk
{
public:
    Disk()  { cout << "  Disk built" << endl; }
    ~Disk() { cout << "  Disk removed" << endl; }
};

class Computer
{
private:
    Processor cpu;              // members are built in this order
    Memory ram;
    Disk disk;

public:
    Computer()  { cout << "  Computer ready" << endl; }
    ~Computer() { cout << "  Computer shutting down" << endl; }
};

int main()
{
    cout << "Creating the computer:" << endl;
    {
        Computer pc;
        cout << "Using the computer..." << endl;
    }
    cout << "Done" << endl;
    return 0;
}
