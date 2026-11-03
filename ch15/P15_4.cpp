// P15.4: Searching contacts.txt
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in("contacts.txt");
    if (!in)
    {
        cout << "Cannot open contacts.txt (run P15.1 first)" << endl;
        return 1;
    }

    string wanted, name, phone;
    cout << "Name to search: ";
    getline(cin, wanted);

    bool found = false;
    while (getline(in, name, ',') && getline(in, phone))
    {
        if (name == wanted)
        {
            cout << "Phone: " << phone << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Not found" << endl;
    in.close();
    return 0;
}
