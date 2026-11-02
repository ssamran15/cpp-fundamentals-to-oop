// P5.9: Batting average
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int runs, innings;
    cout << "Total runs: ";
    cin >> runs;
    cout << "Innings   : ";
    cin >> innings;

    double average = static_cast<double>(runs) / innings;
    cout << fixed << setprecision(2);
    cout << "Batting average: " << average << endl;
    return 0;
}
