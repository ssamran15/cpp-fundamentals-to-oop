// P29.8: A small hospital system from a UML class diagram (see P29.8.md)
#include <iostream>
#include <string>
using namespace std;

class Person                            // base class
{
protected:
    string name;

public:
    Person(string n) : name(n) {}
    virtual ~Person() {}
    string getName() const { return name; }
};

class Patient : public Person           // inheritance: a Patient is a Person
{
private:
    string illness;

public:
    Patient(string n, string i) : Person(n), illness(i) {}
    string getIllness() const { return illness; }
};

class Doctor : public Person            // inheritance: a Doctor is a Person
{
private:
    string speciality;

public:
    Doctor(string n, string s) : Person(n), speciality(s) {}

    // dependency: Doctor only uses a Patient for the length of this call
    void examine(const Patient &p) const
    {
        cout << "  " << name << " (" << speciality << ") examines "
             << p.getName() << " for " << p.getIllness() << endl;
    }
};

class Ward
{
private:
    string name;
    Doctor *inCharge;                   // association: a ward knows its doctor
    Patient *patients[20];              // aggregation: patients exist on their own
    int count;

public:
    Ward() : name(""), inCharge(nullptr), count(0) {}

    void setup(string n, Doctor *d)
    {
        name = n;
        inCharge = d;
    }

    void admit(Patient *p)
    {
        if (count < 20)
            patients[count++] = p;
    }

    void rounds() const
    {
        cout << name << " ward, " << count << " patient(s):" << endl;
        for (int i = 0; i < count; i++)
            inCharge->examine(*patients[i]);
    }
};

class Hospital
{
private:
    string name;
    Ward wards[3];                      // composition: the wards belong to the hospital

public:
    Hospital(string n, Doctor *a, Doctor *b, Doctor *c) : name(n)
    {
        wards[0].setup("Medical", a);
        wards[1].setup("Surgical", b);
        wards[2].setup("Children", c);
    }

    Ward &ward(int i) { return wards[i]; }

    void dailyRounds() const
    {
        cout << name << ": daily rounds" << endl;
        for (int i = 0; i < 3; i++)
            wards[i].rounds();
    }
};

int main()
{
    Doctor d1("Dr. Hina Tariq", "medicine"), d2("Dr. Kamran Yousaf", "surgery"),
           d3("Dr. Nadia Akram", "child health");
    Patient p1("Ali", "fever"), p2("Sana", "a broken arm"), p3("Bilal", "asthma"),
            p4("Zainab", "a cough");

    Hospital h("City Hospital, Okara", &d1, &d2, &d3);
    h.ward(0).admit(&p1);
    h.ward(0).admit(&p3);
    h.ward(1).admit(&p2);
    h.ward(2).admit(&p4);
    h.dailyRounds();
    return 0;
}
