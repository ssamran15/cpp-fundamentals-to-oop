// P24.3: A Register of names with a checked []
#include <iostream>
#include <string>
using namespace std;

class Register
{
private:
    string names[50];
    int count;
    string empty;                   // returned for a bad position

public:
    Register() : count(0), empty("") {}

    bool add(string name)
    {
        if (count == 50)
            return false;
        names[count++] = name;
        return true;
    }

    int size() const { return count; }

    string &operator[](int i)
    {
        if (i < 0 || i >= count)
        {
            cout << "[no student at position " << i << "]" << endl;
            empty = "";
            return empty;
        }
        return names[i];
    }

    const string &operator[](int i) const
    {
        if (i < 0 || i >= count)
        {
            cout << "[no student at position " << i << "]" << endl;
            return empty;
        }
        return names[i];
    }
};

void print(const Register &r)       // uses the const version
{
    for (int i = 0; i < r.size(); i++)
        cout << i + 1 << ". " << r[i] << endl;
}

int main()
{
    Register bscs;
    bscs.add("Ayesha Khan");
    bscs.add("Bilal Ahmed");
    bscs.add("Fatima Noor");
    bscs.add("Hamza Ali");

    print(bscs);

    bscs[1] = "Bilal Ahmad";        // correct a spelling
    cout << "After the correction, position 1: " << bscs[1] << endl;
    string ninth = bscs[9];         // position 9 does not exist
    cout << "Position 9 gave \"" << ninth << "\"" << endl;
    return 0;
}
