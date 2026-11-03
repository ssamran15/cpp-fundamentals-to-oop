// P22.8: A Transcript composed of 5 Subject objects
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Subject
{
private:
    string name;
    int creditHours;
    double gradePoints;

public:
    Subject() : name(""), creditHours(0), gradePoints(0) {}
    Subject(string n, int c, double g) : name(n), creditHours(c), gradePoints(g) {}

    int getCredits() const { return creditHours; }
    double getGradePoints() const { return gradePoints; }

    void show() const
    {
        cout << left << setw(30) << name << right << setw(4) << creditHours
             << setw(8) << gradePoints << endl;
    }
};

class Transcript
{
private:
    string student;
    Subject subjects[5];        // composition: an array of member objects
    int count;

public:
    Transcript(string s) : student(s), count(0) {}

    bool add(const Subject &sub)
    {
        if (count == 5)
            return false;
        subjects[count++] = sub;
        return true;
    }

    double gpa() const
    {
        double points = 0;
        int credits = 0;
        for (int i = 0; i < count; i++)
        {
            points += subjects[i].getGradePoints() * subjects[i].getCredits();
            credits += subjects[i].getCredits();
        }
        return credits == 0 ? 0 : points / credits;
    }

    void show() const
    {
        cout << "Transcript of " << student << endl;
        cout << left << setw(30) << "Subject" << right << setw(4) << "Cr" << setw(8) << "GP" << endl;
        for (int i = 0; i < count; i++)
            subjects[i].show();
        cout << "GPA: " << gpa() << endl;
    }
};

int main()
{
    Transcript t("Ayesha Khan");
    t.add(Subject("Programming Fundamentals", 4, 3.67));
    t.add(Subject("Calculus", 3, 3.00));
    t.add(Subject("Applied Physics", 3, 2.67));
    t.add(Subject("English Composition", 3, 3.33));
    t.add(Subject("Islamic Studies", 2, 4.00));

    cout << fixed << setprecision(2);
    t.show();
    return 0;
}
