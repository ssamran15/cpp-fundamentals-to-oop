// P10.2: Days above the average temperature
#include <iostream>
using namespace std;

int main()
{
    const int DAYS = 7;
    double temp[DAYS];
    double sum = 0;

    for (int i = 0; i < DAYS; i++)
    {
        cout << "Temperature on day " << i + 1 << ": ";
        cin >> temp[i];
        sum += temp[i];
    }

    double average = sum / DAYS;
    cout << "Average temperature = " << average << endl;
    cout << "Days above the average:";
    for (int i = 0; i < DAYS; i++)
        if (temp[i] > average)
            cout << " " << i + 1;
    cout << endl;
    return 0;
}
