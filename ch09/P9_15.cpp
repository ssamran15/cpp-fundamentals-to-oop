// P9.15: Tossing a coin 100 times
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char tossCoin();

int main()
{
    srand(time(0));

    int heads = 0, tails = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (tossCoin() == 'H')
            heads++;
        else
            tails++;
    }
    cout << "Heads: " << heads << endl;
    cout << "Tails: " << tails << endl;
    return 0;
}

char tossCoin()
{
    if (rand() % 2 == 0)
        return 'H';
    return 'T';
}
