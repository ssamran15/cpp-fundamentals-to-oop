// P32.8: Totals and class positions from a file
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream in("marks2.txt");
    if (!in)
    {
        cout << "Cannot open marks2.txt" << endl;
        return 1;
    }

    vector<string> names;
    vector<vector<int>> marks;          // one row per student, any length

    string line;
    while (getline(in, line))
    {
        istringstream parts(line);
        string name;
        if (!(parts >> name))
            continue;                   // skip a blank line
        vector<int> row;
        int m;
        while (parts >> m)
            row.push_back(m);
        names.push_back(name);
        marks.push_back(row);
    }
    in.close();

    int n = names.size();
    vector<int> total(n, 0);
    for (int i = 0; i < n; i++)
        for (int m : marks[i])
            total[i] += m;

    cout << left << setw(10) << "Name" << right << setw(10) << "Subjects"
         << setw(8) << "Total" << setw(10) << "Position" << endl;
    for (int i = 0; i < n; i++)
    {
        int position = 1;               // 1 + the number of students with a higher total
        for (int j = 0; j < n; j++)
            if (total[j] > total[i])
                position++;
        cout << left << setw(10) << names[i] << right << setw(10) << marks[i].size()
             << setw(8) << total[i] << setw(10) << position << endl;
    }
    return 0;
}
