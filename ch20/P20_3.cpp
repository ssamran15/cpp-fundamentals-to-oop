// P20.3: Finding the topper with this-> and isBetterThan
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    double cgpa;

public:
    void set(string name, double cgpa)
    {
        this->name = name;          // the member name = the parameter name
        this->cgpa = cgpa;
    }

    bool isBetterThan(const Student &other)
    {
        return cgpa > other.cgpa;
    }

    void show()
    {
        cout << name << " (CGPA " << cgpa << ")" << endl;
    }
};

int main()
{
    Student s[5];
    s[0].set("Ayesha Khan", 3.62);
    s[1].set("Bilal Ahmed", 3.15);
    s[2].set("Fatima Noor", 3.88);
    s[3].set("Hamza Ali", 2.94);
    s[4].set("Sana Tariq", 3.71);

    int top = 0;
    for (int i = 1; i < 5; i++)
        if (s[i].isBetterThan(s[top]))
            top = i;

    cout << "Topper: ";
    s[top].show();
    return 0;
}
