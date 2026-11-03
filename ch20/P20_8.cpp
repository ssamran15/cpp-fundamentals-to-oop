// P20.8: An array of Tracer objects passed by value and by reference
#include <iostream>
using namespace std;

class Tracer                    // the class of Program 20.8
{
private:
    int id;

public:
    Tracer(int i) : id(i)
    {
        cout << "  constructor " << id << endl;
    }

    Tracer(const Tracer &other) : id(other.id + 100)
    {
        cout << "  copy constructor " << id << " (copied from " << other.id << ")" << endl;
    }

    ~Tracer()
    {
        cout << "  destructor " << id << endl;
    }

    int getId() { return id; }
};

void byValue(Tracer t)
{
    cout << "  inside byValue, id = " << t.getId() << endl;
}

void byReference(Tracer &t)
{
    cout << "  inside byReference, id = " << t.getId() << endl;
}

int main()
{
    cout << "1. Create the array" << endl;
    Tracer list[3] = { Tracer(1), Tracer(2), Tracer(3) };

    cout << "2. byValue(list[0])" << endl;
    byValue(list[0]);

    cout << "3. byReference(list[1])" << endl;
    byReference(list[1]);

    cout << "4. End of main" << endl;
    return 0;
}
