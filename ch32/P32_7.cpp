// P32.7: Words of a file, sorted by length
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool shorterFirst(const string &a, const string &b)
{
    if (a.length() != b.length())
        return a.length() < b.length();
    return a < b;                       // same length: alphabetical order
}

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

    vector<string> words;
    string w;
    while (in >> w)
        words.push_back(w);
    in.close();

    cout << "Number of words: " << words.size() << endl;
    if (words.empty())
        return 0;

    string longest = words[0];
    for (const string &x : words)
        if (x.length() > longest.length())
            longest = x;
    cout << "Longest word: " << longest << endl;

    sort(words.begin(), words.end(), shorterFirst);
    cout << "Sorted by length:" << endl;
    for (const string &x : words)
        cout << "  " << x << endl;
    return 0;
}
