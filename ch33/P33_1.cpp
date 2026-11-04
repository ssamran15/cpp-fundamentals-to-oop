// P33.1: Division with a runtime_error, all pairs processed
#include <iostream>
#include <stdexcept>
using namespace std;

double divide(double a, double b)
{
    if (b == 0)
        throw runtime_error("division by zero");
    return a / b;
}

int main()
{
    double top[5] = { 45, 7, 100, 3.5, 0 };
    double bottom[5] = { 9, 0, 8, 0, 4 };

    for (int i = 0; i < 5; i++)
    {
        try
        {
            double result = divide(top[i], bottom[i]);  // if this throws, nothing is printed
            cout << top[i] << " / " << bottom[i] << " = " << result << endl;
        }
        catch (const runtime_error &e)
        {
            cout << top[i] << " / " << bottom[i] << ": error, " << e.what() << endl;
        }
    }
    cout << "All five pairs processed" << endl;
    return 0;
}
