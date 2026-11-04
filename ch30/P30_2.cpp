// P30.2: Valid and invalid temperature entries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in("temperatures.txt");
    if (!in)
    {
        cout << "Cannot open temperatures.txt" << endl;
        return 1;
    }

    double t, sum = 0;
    int valid = 0, invalid = 0;
    while (true)
    {
        if (in >> t)
        {
            sum += t;
            valid++;
        }
        else if (in.eof())
            break;                          // the real end of the file
        else
        {
            in.clear();                     // reset the fail state
            string junk;
            in >> junk;                     // skip the bad entry
            cout << "Skipped \"" << junk << "\"" << endl;
            invalid++;
        }
    }
    in.close();

    cout << "Valid entries: " << valid << ", invalid entries: " << invalid << endl;
    if (valid > 0)
        cout << "Average of the valid entries: " << sum / valid << endl;
    return 0;
}
