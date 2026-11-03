// P15.2: Characters, words and lines in a file
#include <iostream>
#include <fstream>
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

    int chars = 0, words = 0, lines = 0;
    bool inWord = false;
    char ch;
    while (in.get(ch))
    {
        if (ch == '\n')
            lines++;
        else
            chars++;                            // newlines are not counted as characters

        if (ch == ' ' || ch == '\n' || ch == '\t')
            inWord = false;
        else if (!inWord)
        {
            inWord = true;                      // the start of a new word
            words++;
        }
    }
    in.close();

    cout << "Characters: " << chars << endl;
    cout << "Words: " << words << endl;
    cout << "Lines: " << lines << endl;
    return 0;
}
