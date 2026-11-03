// P9.4: Seconds to hours, minutes and seconds
#include <iostream>
using namespace std;

void convertTime(int totalSeconds, int &h, int &m, int &s);

int main()
{
    int total, h, m, s;
    cout << "Enter time in seconds: ";
    cin >> total;
    convertTime(total, h, m, s);
    cout << total << " seconds = " << h << " h " << m << " min " << s << " s" << endl;
    return 0;
}

void convertTime(int totalSeconds, int &h, int &m, int &s)
{
    h = totalSeconds / 3600;
    m = totalSeconds % 3600 / 60;
    s = totalSeconds % 60;
}
