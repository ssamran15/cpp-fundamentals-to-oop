// P15.7: Students in each program
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in("students.csv");
    if (!in)
    {
        cout << "Cannot open students.csv" << endl;
        return 1;
    }

    const int MAX = 20;
    string programName[MAX];         // the programs found so far
    int count[MAX] = {0};
    int programs = 0;

    string roll, name, program;
    while (getline(in, roll, ',') && getline(in, name, ',') && getline(in, program))
    {
        int k = 0;
        while (k < programs && programName[k] != program)
            k++;
        if (k == programs && programs < MAX)     // a program not seen before
        {
            programName[k] = program;
            programs++;
        }
        if (k < MAX)
            count[k]++;
    }
    in.close();

    cout << "Program   Students" << endl;
    for (int k = 0; k < programs; k++)
        cout << programName[k] << "      " << count[k] << endl;
    return 0;
}
