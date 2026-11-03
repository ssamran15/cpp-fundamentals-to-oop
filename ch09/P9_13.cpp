// P9.13: 600 rolls of a dice
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int rollDice();

int main()
{
    srand(time(0));

    int ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0;
    for (int i = 1; i <= 600; i++)
    {
        switch (rollDice())
        {
            case 1: ones++;   break;
            case 2: twos++;   break;
            case 3: threes++; break;
            case 4: fours++;  break;
            case 5: fives++;  break;
            case 6: sixes++;  break;
        }
    }

    cout << "Face  Count" << endl;
    cout << "1     " << ones << endl;
    cout << "2     " << twos << endl;
    cout << "3     " << threes << endl;
    cout << "4     " << fours << endl;
    cout << "5     " << fives << endl;
    cout << "6     " << sixes << endl;
    return 0;
}

int rollDice()
{
    return rand() % 6 + 1;
}
