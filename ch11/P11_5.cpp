// P11.5: Weekly sales of 4 salesmen
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int MEN = 4, DAYS = 7;
    int sales[MEN][DAYS] = {
        {12000,  9500, 15000, 11000,  8700, 16500, 14000},
        { 8000, 10200,  9900, 12500, 11300,  9000, 13400},
        {15500, 14200, 16800, 13900, 15100, 17600, 18200},
        { 9800,  8800, 10400,  9600, 12100, 11700, 10900}
    };

    int best = 0, bestTotal = 0;
    cout << "Weekly total of each salesman" << endl;
    for (int i = 0; i < MEN; i++)
    {
        int total = 0;
        for (int j = 0; j < DAYS; j++)
            total += sales[i][j];
        cout << "Salesman " << i + 1 << ": Rs. " << total << endl;
        if (total > bestTotal)
        {
            bestTotal = total;
            best = i;
        }
    }

    cout << endl << "Total sales of each day" << endl;
    for (int j = 0; j < DAYS; j++)
    {
        int total = 0;
        for (int i = 0; i < MEN; i++)
            total += sales[i][j];
        cout << "Day " << j + 1 << ": Rs. " << total << endl;
    }

    cout << endl << "Best salesman of the week: Salesman " << best + 1
         << " (Rs. " << bestTotal << ")" << endl;
    return 0;
}
