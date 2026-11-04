// P30.5: A bill built with string streams
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    ifstream in("purchases.txt");
    if (!in)
    {
        cout << "Cannot open purchases.txt" << endl;
        return 1;
    }

    string line;
    double total = 0;
    while (getline(in, line))
    {
        istringstream parts(line);          // split the line
        string item;
        int qty;
        double price;
        if (!(parts >> item >> qty >> price))
            continue;                       // skip a badly formed line

        ostringstream row;                  // build the output line
        row << fixed << setprecision(2) << left << setw(12) << item << right
            << setw(4) << qty << " x " << setw(8) << price << " = " << setw(9) << qty * price;
        cout << row.str() << endl;
        total += qty * price;
    }
    in.close();

    ostringstream last;
    last << fixed << setprecision(2) << "Total: Rs. " << total;
    cout << string(last.str().length(), '-') << endl << last.str() << endl;
    return 0;
}
