// P15.5: Copying a file in capital letters
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string source, target;
    cout << "Source file: ";
    cin >> source;
    cout << "New file: ";
    cin >> target;

    ifstream in(source);
    if (!in)
    {
        cout << "Cannot open " << source << endl;
        return 1;
    }
    ofstream out(target);

    char ch;
    int count = 0;
    while (in.get(ch))
    {
        out.put(toupper(ch));
        count++;
    }
    in.close();
    out.close();

    cout << count << " characters copied to " << target << endl;
    return 0;
}
