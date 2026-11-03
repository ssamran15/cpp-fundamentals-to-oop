// P15.6: Merging two sorted files
#include <iostream>
#include <fstream>
using namespace std;

bool readNext(ifstream &f, int &x);

int main()
{
    ifstream f1("numbers1.txt"), f2("numbers2.txt");
    if (!f1 || !f2)
    {
        cout << "Cannot open the input files" << endl;
        return 1;
    }
    ofstream out("merged.txt");

    int a, b, count = 0;
    bool hasA = readNext(f1, a);
    bool hasB = readNext(f2, b);

    while (hasA && hasB)
    {
        if (a <= b)
        {
            out << a << " ";
            hasA = readNext(f1, a);
        }
        else
        {
            out << b << " ";
            hasB = readNext(f2, b);
        }
        count++;
    }
    while (hasA)                                 // what is left in the first file
    {
        out << a << " ";
        hasA = readNext(f1, a);
        count++;
    }
    while (hasB)                                 // what is left in the second file
    {
        out << b << " ";
        hasB = readNext(f2, b);
        count++;
    }
    out << endl;
    f1.close();
    f2.close();
    out.close();

    cout << count << " numbers written to merged.txt" << endl;
    return 0;
}

// reads the next number of the file into x; returns false at the end of the file
bool readNext(ifstream &f, int &x)
{
    if (f >> x)
        return true;
    return false;
}
