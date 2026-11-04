// P30.8: Lines, words and the longest line of a file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string fileName;
    cout << "File name: ";
    cin >> fileName;

    ifstream in(fileName);
    if (!in)
    {
        cout << "Cannot open " << fileName << endl;
        return 1;
    }

    string line, longest;
    int lines = 0, words = 0;
    while (getline(in, line))
    {
        lines++;
        istringstream ws(line);
        string w;
        while (ws >> w)                     // >> skips the spaces between words
            words++;
        if (line.length() > longest.length())
            longest = line;
    }
    in.close();

    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Longest line (" << longest.length() << " characters): " << longest << endl;
    return 0;
}
