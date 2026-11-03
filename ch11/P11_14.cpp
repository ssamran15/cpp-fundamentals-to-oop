// P11.14: Finding a roll number by name
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const int N = 6;
    char names[N][30] = {"Ayesha Khan", "Bilal Ahmed", "Fatima Noor",
                         "Hamza Ali", "Sana Tariq", "Usman Raza"};
    int roll[N] = {201, 202, 203, 204, 205, 206};

    char name[30];
    cout << "Enter a name: ";
    cin.getline(name, 30);

    int pos = -1;
    for (int i = 0; i < N; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
        cout << name << " is not in the list" << endl;
    else
        cout << "Roll number of " << names[pos] << ": " << roll[pos] << endl;
    return 0;
}
