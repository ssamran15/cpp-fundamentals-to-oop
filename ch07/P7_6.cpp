// P7.6: PIN with at most three tries
#include <iostream>
using namespace std;

int main()
{
    const int CORRECT_PIN = 1234;
    int pin, tries = 0;
    bool accepted = false;

    while (tries < 3)
    {
        cout << "Enter PIN: ";
        cin >> pin;
        tries++;
        if (pin == CORRECT_PIN)
        {
            accepted = true;
            break;
        }
        cout << "Wrong PIN" << endl;
    }

    if (accepted)
        cout << "PIN accepted" << endl;
    else
        cout << "Card blocked" << endl;
    return 0;
}
