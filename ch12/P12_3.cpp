// P12.3: User name and domain of an email address
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string email;
    cout << "Enter an email address: ";
    cin >> email;

    size_t at = email.find('@');
    if (at == string::npos)
    {
        cout << "Error: the address has no @" << endl;
        return 1;
    }
    cout << "User name: " << email.substr(0, at) << endl;
    cout << "Domain: " << email.substr(at + 1, email.length() - at - 1) << endl;
    return 0;
}
