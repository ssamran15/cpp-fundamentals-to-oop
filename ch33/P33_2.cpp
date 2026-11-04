// P33.2: Reading a valid age with exceptions
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
using namespace std;

int readAge()
{
    string line;
    cout << "Age: ";
    getline(cin, line);

    // stoi("25abc") would quietly give 25, so check every character first
    if (line.empty())
        throw invalid_argument("nothing was typed");
    for (char ch : line)
        if (!isdigit(ch))
            throw invalid_argument("\"" + line + "\" is not a number");

    int age;
    try
    {
        age = stoi(line);
    }
    catch (const out_of_range &)    // too big for an int: give a clearer message
    {
        throw out_of_range(line + " is far too large");
    }
    if (age < 16 || age > 60)
        throw out_of_range("age " + to_string(age) + " is not from 16 to 60");
    return age;
}

int main()
{
    while (true)
    {
        try
        {
            int age = readAge();
            cout << "Accepted: " << age << endl;
            break;
        }
        catch (const invalid_argument &e)
        {
            cout << "Invalid: " << e.what() << endl;
        }
        catch (const out_of_range &e)
        {
            cout << "Out of range: " << e.what() << endl;
        }
    }
    return 0;
}
