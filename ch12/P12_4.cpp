// P12.4: Checking a CNIC number
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string cnic;
    cout << "Enter CNIC (e.g. 35202-1234567-1): ";
    cin >> cnic;

    bool valid = true;
    if (cnic.length() != 15)
    {
        cout << "Invalid: a CNIC has 15 characters" << endl;
        valid = false;
    }
    else
    {
        for (int i = 0; i < 15; i++)
        {
            if (i == 5 || i == 13)
            {
                if (cnic[i] != '-')
                {
                    cout << "Invalid: a dash is needed at position " << i + 1 << endl;
                    valid = false;
                }
            }
            else if (!isdigit(cnic[i]))
            {
                cout << "Invalid: position " << i + 1 << " must be a digit" << endl;
                valid = false;
            }
        }
    }
    if (valid)
        cout << "The CNIC format is valid" << endl;
    return 0;
}
