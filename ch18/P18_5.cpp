// P18.5: A Result class with member functions defined outside
#include <iostream>
using namespace std;

class Result
{
private:
    int marks[5];

public:
    void input();
    int highest();
    int lowest();
    double average();
    char grade();
};

void Result::input()
{
    cout << "Enter marks in 5 subjects: ";
    for (int i = 0; i < 5; i++)
        cin >> marks[i];
}

int Result::highest()
{
    int h = marks[0];
    for (int i = 1; i < 5; i++)
        if (marks[i] > h)
            h = marks[i];
    return h;
}

int Result::lowest()
{
    int l = marks[0];
    for (int i = 1; i < 5; i++)
        if (marks[i] < l)
            l = marks[i];
    return l;
}

double Result::average()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += marks[i];
    return sum / 5.0;
}

char Result::grade()
{
    double avg = average();
    if (avg >= 80) return 'A';
    if (avg >= 65) return 'B';
    if (avg >= 50) return 'C';
    return 'F';
}

int main()
{
    Result r;
    r.input();
    cout << "Highest: " << r.highest() << endl;
    cout << "Lowest: " << r.lowest() << endl;
    cout << "Average: " << r.average() << endl;
    cout << "Grade: " << r.grade() << endl;
    return 0;
}
