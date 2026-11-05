// P15.12: Checking arguments with assert
#include <iostream>
#include <cassert>
using namespace std;

double percentage(int obtained, int total);

int main()
{
    int obtained, total;
    cout << "Obtained marks and total marks: ";
    cin >> obtained >> total;
    double p = percentage(obtained, total);
    cout << "Percentage = " << p << "%" << endl;
    return 0;
}

double percentage(int obtained, int total)
{
    assert(total > 0);
    assert(obtained >= 0 && obtained <= total);
    return obtained * 100.0 / total;
}
