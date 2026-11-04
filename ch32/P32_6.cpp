// P32.6: The Stack template of Program 31.7 built on a vector
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
private:
    vector<T> items;                    // no fixed size any more

public:
    void push(const T &x) { items.push_back(x); }      // never full

    bool pop(T &x)
    {
        if (items.empty())
            return false;               // stack empty
        x = items.back();
        items.pop_back();
        return true;
    }

    bool isEmpty() const { return items.empty(); }
    int size() const { return items.size(); }
};

int main()
{
    Stack<int> numbers;
    for (int i = 1; i <= 100; i++)      // more than the old limit of 50
        numbers.push(i * 10);
    cout << "Pushed " << numbers.size() << " numbers" << endl;

    int n, shown = 0;
    cout << "The top five:";
    while (shown < 5 && numbers.pop(n))
    {
        cout << " " << n;
        shown++;
    }
    cout << endl << numbers.size() << " numbers left" << endl;

    Stack<string> pages;
    pages.push("Home");
    pages.push("Admissions");
    pages.push("Fee Structure");
    string page;
    cout << "Going back through pages:" << endl;
    while (pages.pop(page))
        cout << "  " << page << endl;
    return 0;
}
