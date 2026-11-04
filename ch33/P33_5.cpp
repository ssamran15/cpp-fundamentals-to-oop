// P33.5: Average of the valid marks in a file
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

double averageOf(const string &fileName)
{
    ifstream in(fileName);
    if (!in)
        throw runtime_error("cannot open " + fileName);

    string line;
    int lineNo = 0, count = 0;
    double sum = 0;
    while (getline(in, line))
    {
        lineNo++;
        try
        {
            sum += stoi(line);
            count++;
        }
        catch (const invalid_argument &)
        {
            cout << "Line " << lineNo << " skipped: \"" << line << "\" is not a number" << endl;
        }
    }
    if (count == 0)
        throw runtime_error("no valid marks in " + fileName);
    return sum / count;
}

int main()
{
    string fileName;
    cout << "File name: ";
    cin >> fileName;
    try
    {
        double avg = averageOf(fileName);
        cout << "Average of the valid marks: " << avg << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
