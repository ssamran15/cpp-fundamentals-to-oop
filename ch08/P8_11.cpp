// P8.11: Student result with functions
#include <iostream>
#include <iomanip>
using namespace std;

int inputMarks();
double calculatePercentage(int obtained, int total);
void findDivision(double percent);

int main()
{
    const int TOTAL = 1100;
    int obtained = inputMarks();
    double percent = calculatePercentage(obtained, TOTAL);

    cout << fixed << setprecision(2);
    cout << "Marks: " << obtained << " / " << TOTAL << endl;
    cout << "Percentage: " << percent << "%" << endl;
    findDivision(percent);
    return 0;
}

int inputMarks()
{
    int marks;
    cout << "Enter obtained marks (out of 1100): ";
    cin >> marks;
    while (marks < 0 || marks > 1100)
    {
        cout << "Invalid marks. Enter again: ";
        cin >> marks;
    }
    return marks;
}

double calculatePercentage(int obtained, int total)
{
    return obtained * 100.0 / total;
}

void findDivision(double percent)
{
    cout << "Division: ";
    if (percent >= 60)
        cout << "First" << endl;
    else if (percent >= 45)
        cout << "Second" << endl;
    else if (percent >= 33)
        cout << "Third" << endl;
    else
        cout << "Fail" << endl;
}
