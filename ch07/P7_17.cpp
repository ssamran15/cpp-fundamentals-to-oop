// P7.17: 1 to 50 except multiples of 5, using continue
#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 50; i++)
    {
        if (i % 5 == 0)
            continue;       // skip the rest of this pass
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
