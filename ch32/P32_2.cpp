// P32.2: Sorted names without repeats
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> names;
    string name;
    cout << "Enter names (end to stop): ";
    cin >> name;
    while (name != "end")
    {
        names.push_back(name);
        cin >> name;
    }

    sort(names.begin(), names.end());   // equal names are now side by side

    vector<string> different;
    for (const string &n : names)
        if (different.empty() || n != different.back())
            different.push_back(n);

    cout << different.size() << " different names:" << endl;
    for (const string &n : different)
        cout << "  " << n << endl;
    return 0;
}
