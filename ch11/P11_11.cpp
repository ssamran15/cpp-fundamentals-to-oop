// P11.11: Password rules
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    char password[50];
    cout << "Enter a password: ";
    cin.getline(password, 50);

    bool upper = false, lower = false, digit = false;
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i])) upper = true;
        if (islower(password[i])) lower = true;
        if (isdigit(password[i])) digit = true;
    }

    bool ok = true;
    if (strlen(password) < 8)
    {
        cout << "Fails: at least 8 characters" << endl;
        ok = false;
    }
    if (!upper)
    {
        cout << "Fails: at least one uppercase letter" << endl;
        ok = false;
    }
    if (!lower)
    {
        cout << "Fails: at least one lowercase letter" << endl;
        ok = false;
    }
    if (!digit)
    {
        cout << "Fails: at least one digit" << endl;
        ok = false;
    }
    if (ok)
        cout << "The password is strong" << endl;
    return 0;
}
