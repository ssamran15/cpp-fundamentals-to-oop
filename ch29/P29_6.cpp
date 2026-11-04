// P29.6: Aggregation: players outlive their team
#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
    string name;

public:
    Player(string n) : name(n) {}
    string getName() const { return name; }
};

class Team
{
private:
    string name;
    Player *players[11];
    int count;

public:
    Team(string n) : name(n), count(0) {}
    ~Team() { cout << "[Team " << name << " destroyed]" << endl; }   // players are not deleted

    void add(Player *p)
    {
        if (count < 11)
            players[count++] = p;
    }

    void show() const
    {
        cout << name << ":";
        for (int i = 0; i < count; i++)
            cout << " " << players[i]->getName();
        cout << endl;
    }
};

int main()
{
    Player a("Hamza"), b("Usman"), c("Bilal");

    {
        Team t1("Okara Eagles");
        t1.add(&a);
        t1.add(&b);
        t1.add(&c);
        t1.show();
    }                                   // t1 ends here

    cout << "The players still exist: " << a.getName() << ", " << b.getName()
         << ", " << c.getName() << endl;

    Team t2("Sahiwal Stars");
    t2.add(&a);
    t2.add(&c);
    t2.show();
    return 0;
}
