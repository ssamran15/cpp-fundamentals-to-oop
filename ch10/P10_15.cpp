// P10.15: 6,000 rolls with a count array
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    int count[7] = {0};          // count[1] to count[6]; count[0] is not used
    for (int i = 1; i <= 6000; i++)
        count[rand() % 6 + 1]++;

    cout << "Face  Count" << endl;
    for (int face = 1; face <= 6; face++)
        cout << face << "     " << count[face] << endl;
    return 0;
}
