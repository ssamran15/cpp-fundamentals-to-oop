// P14.9: Names in C-strings of exactly the right size
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cout << "How many names? ";
    cin >> n;
    cin.ignore(100, '\n');

    char **names = new char*[n];
    char buffer[100];
    int bytes = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Name " << i + 1 << ": ";
        cin.getline(buffer, 100);
        int size = strlen(buffer) + 1;          // + 1 for the '\0'
        names[i] = new char[size];
        strcpy(names[i], buffer);
        bytes += size;
    }

    cout << endl << "Names stored:" << endl;
    for (int i = 0; i < n; i++)
        cout << names[i] << " (" << strlen(names[i]) + 1 << " bytes)" << endl;
    cout << "Total bytes used for the names: " << bytes << endl;

    for (int i = 0; i < n; i++)
        delete[] names[i];
    delete[] names;
    return 0;
}
