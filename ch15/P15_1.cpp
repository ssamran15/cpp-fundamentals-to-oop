// P15.1: Writing and reading contacts.txt
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    ofstream out("contacts.txt");
    if (!out)
    {
        cout << "Cannot create contacts.txt" << endl;
        return 1;
    }

    string name, phone;
    for (int i = 1; i <= 5; i++)
    {
        cout << "Friend " << i << " name: ";
        getline(cin, name);
        cout << "Phone: ";
        getline(cin, phone);
        out << name << "," << phone << endl;       // one friend per line
    }
    out.close();

    ifstream in("contacts.txt");
    if (!in)
    {
        cout << "Cannot open contacts.txt" << endl;
        return 1;
    }

    cout << endl << left << setw(20) << "Name" << "Phone" << endl;
    cout << "-----------------------------------" << endl;
    while (getline(in, name, ',') && getline(in, phone))
        cout << left << setw(20) << name << phone << endl;
    in.close();
    return 0;
}
