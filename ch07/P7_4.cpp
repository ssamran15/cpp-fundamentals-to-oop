// P7.4: Largest and smallest until 0 is entered
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter numbers (0 to stop): ";
    cin >> n;

    if (n == 0)
    {
        cout << "No numbers were entered" << endl;
        return 0;
    }

    int largest = n, smallest = n;
    while (n != 0)
    {
        if (n > largest)
            largest = n;
        if (n < smallest)
            smallest = n;
        cin >> n;
    }
    cout << "Largest : " << largest << endl;
    cout << "Smallest: " << smallest << endl;
    return 0;
}
