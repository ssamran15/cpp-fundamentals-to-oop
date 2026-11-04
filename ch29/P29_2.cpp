// P29.2: A Result class derived from Student and Sportsman
#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;
    int marks;                  // out of 500

public:
    Student(string n, int m) : name(n), marks(m) {}
};

class Sportsman
{
protected:
    string sport;
    int score;

public:
    Sportsman(string s, int sc) : sport(s), score(sc) {}
};

class Result : public Student, public Sportsman
{
public:
    Result(string n, int m, string s, int sc) : Student(n, m), Sportsman(s, sc) {}

    int bonus() const
    {
        if (score >= 80) return 20;
        if (score >= 50) return 10;
        return 0;
    }

    void show() const
    {
        cout << name << " (" << sport << ", score " << score << "): " << marks
             << " + bonus " << bonus() << " = " << marks + bonus() << " / 500" << endl;
    }
};

int main()
{
    Result r1("Hamza Ali", 412, "Cricket", 86);
    Result r2("Sana Tariq", 437, "Badminton", 64);
    Result r3("Usman Raza", 398, "Hockey", 35);
    r1.show();
    r2.show();
    r3.show();
    return 0;
}
