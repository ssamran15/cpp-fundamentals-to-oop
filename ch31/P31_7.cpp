// P31.7: A Stats class template for marks and temperatures
#include <iostream>
using namespace std;

template <typename T>
class Stats
{
private:
    T values[100];
    int count;

public:
    Stats() : count(0) {}

    bool add(const T &x)
    {
        if (count == 100)
            return false;
        values[count++] = x;
        return true;
    }

    double mean() const
    {
        if (count == 0)
            return 0;
        double sum = 0;
        for (int i = 0; i < count; i++)
            sum += values[i];
        return sum / count;
    }

    T smallest() const
    {
        T s = values[0];
        for (int i = 1; i < count; i++)
            if (values[i] < s)
                s = values[i];
        return s;
    }

    T largest() const
    {
        T l = values[0];
        for (int i = 1; i < count; i++)
            if (values[i] > l)
                l = values[i];
        return l;
    }
};

int main()
{
    Stats<int> marks;
    int m[6] = { 72, 85, 64, 91, 58, 77 };
    for (int i = 0; i < 6; i++)
        marks.add(m[i]);
    cout << "Marks: mean " << marks.mean() << ", smallest " << marks.smallest()
         << ", largest " << marks.largest() << endl;

    Stats<double> temps;
    double t[7] = { 31.5, 33.0, 29.5, 35.0, 36.5, 30.0, 32.0 };
    for (int i = 0; i < 7; i++)
        temps.add(t[i]);
    cout << "Temperatures: mean " << temps.mean() << ", lowest " << temps.smallest()
         << ", highest " << temps.largest() << endl;
    return 0;
}
