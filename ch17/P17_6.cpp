// P17.6: A Tasbeeh counter class
#include <iostream>
using namespace std;

class Tasbeeh
{
private:
    int count;

public:
    void press()
    {
        count++;
    }

    void reset()
    {
        count = 0;
    }

    void show()
    {
        cout << "Count: " << count << endl;
    }
};

int main()
{
    Tasbeeh t;
    t.reset();                          // start from zero

    int n;
    cout << "How many times to press? ";
    cin >> n;
    for (int i = 1; i <= n; i++)
        t.press();
    t.show();

    t.reset();
    cout << "After reset, ";
    t.show();
    return 0;
}
