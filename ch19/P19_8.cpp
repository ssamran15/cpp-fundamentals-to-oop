// P19.8: Watching constructors and destructors with a Tracer class
#include <iostream>
using namespace std;

class Tracer
{
private:
    int id;

public:
    Tracer(int n) : id(n)
    {
        cout << "  Tracer " << id << " created" << endl;
    }

    ~Tracer()
    {
        cout << "  Tracer " << id << " destroyed" << endl;
    }
};

void work(int n)
{
    cout << " work(" << n << ") starts" << endl;
    Tracer t(n);
    cout << " work(" << n << ") ends" << endl;
}

int main()
{
    cout << "1. Inside a for loop body:" << endl;
    for (int i = 1; i <= 2; i++)
    {
        Tracer t(i);                    // a new object every time round
        cout << "  (loop body " << i << ")" << endl;
    }

    cout << "2. Inside a function called twice:" << endl;
    work(10);
    work(20);

    cout << "3. With new and delete:" << endl;
    Tracer *p = new Tracer(99);
    cout << "  (p is in use)" << endl;
    delete p;

    cout << "4. A local object of main:" << endl;
    Tracer last(100);
    cout << "End of main" << endl;
    return 0;
}
