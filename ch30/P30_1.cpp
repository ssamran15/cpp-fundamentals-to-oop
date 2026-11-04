// P30.1: One function for cout and for a file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void table(ostream &out, int n)         // works with any output stream
{
    for (int i = 1; i <= 10; i++)
        out << n << " x " << i << " = " << n * i << endl;
}

int main()
{
    cout << "Table of 7 on the screen:" << endl;
    table(cout, 7);

    ofstream file("table9.txt");
    table(file, 9);                     // the same function writes to a file
    file.close();

    ifstream in("table9.txt");
    string line;
    int lines = 0;
    while (getline(in, line))
        lines++;
    in.close();
    cout << "table9.txt has " << lines << " lines" << endl;
    return 0;
}
