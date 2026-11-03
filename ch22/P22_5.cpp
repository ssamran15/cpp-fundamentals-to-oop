// P22.5: Aggregation: the same Player in two teams
#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
    string name;
    int runs;

public:
    Player(string n) : name(n), runs(0) {}
    void addRuns(int r) { runs += r; }
    string getName() const { return name; }
    int getRuns() const { return runs; }
};

class Team
{
private:
    string name;
    Player *players[11];        // pointers: the team does not own its players
    int count;

public:
    Team(string n) : name(n), count(0) {}

    bool add(Player *p)
    {
        if (count == 11)
            return false;
        players[count++] = p;
        return true;
    }

    void show() const
    {
        cout << name << " (" << count << " players):" << endl;
        for (int i = 0; i < count; i++)
            cout << "  " << players[i]->getName() << ", " << players[i]->getRuns() << " runs" << endl;
    }
};

int main()
{
    Player hamza("Hamza Ali"), usman("Usman Raza"), bilal("Bilal Ahmed");

    Team club("Okara Eagles");
    Team national("National XI");

    club.add(&hamza);
    club.add(&usman);
    national.add(&hamza);       // the same player in both teams
    national.add(&bilal);

    hamza.addRuns(75);          // one change, seen by both teams
    usman.addRuns(32);
    bilal.addRuns(48);

    club.show();
    national.show();
    return 0;
}
