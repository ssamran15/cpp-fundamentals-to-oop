// P27.3: Program 26.8 with show() made virtual
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;

public:
    Person(string n) : name(n) {}
    virtual ~Person() {}

    virtual void show() const { cout << "Person: " << name << endl; }
};

class Student : public Person
{
private:
    int rollNo;

public:
    Student(string n, int r) : Person(n), rollNo(r) {}

    void show() const override { cout << "Student: " << name << ", roll no " << rollNo << endl; }
};

void printCard(const Person &p)
{
    cout << "Library card -> ";
    p.show();
}

int main()
{
    Person p("Ali Raza");
    Student s("Ayesha Khan", 2417);

    printCard(p);
    printCard(s);                       // 1. through a reference: now virtual

    Person copy = s;                    // 2. a copy of the Person part only
    copy.show();

    Person *ptr = &s;                   // 3. through a pointer: now virtual
    ptr->show();
    return 0;
}
