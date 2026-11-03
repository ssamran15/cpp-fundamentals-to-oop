// P23.7: A MyString class with =, +, += and ==
#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
    char *text;

public:
    MyString(const char *s = "")
    {
        text = new char[strlen(s) + 1];
        strcpy(text, s);
    }

    MyString(const MyString &other)
    {
        text = new char[strlen(other.text) + 1];
        strcpy(text, other.text);
    }

    ~MyString()
    {
        delete[] text;
    }

    MyString &operator=(const MyString &other)
    {
        if (this == &other)
            return *this;
        delete[] text;
        text = new char[strlen(other.text) + 1];
        strcpy(text, other.text);
        return *this;
    }

    MyString operator+(const MyString &other) const
    {
        char *joined = new char[strlen(text) + strlen(other.text) + 1];
        strcpy(joined, text);
        strcat(joined, other.text);
        MyString result(joined);
        delete[] joined;                // result has its own copy
        return result;
    }

    MyString &operator+=(const MyString &other)
    {
        *this = *this + other;          // reuse + and =
        return *this;
    }

    bool operator==(const MyString &other) const
    {
        return strcmp(text, other.text) == 0;
    }

    void show() const
    {
        cout << text << endl;
    }
};

int main()
{
    MyString first("Govt. Graduate"), second(" College"), place(", Okara");

    MyString name = first + second;
    cout << "first + second: "; name.show();

    name += place;
    cout << "After += place: "; name.show();

    MyString copy;
    copy = name;
    cout << "copy:           "; copy.show();
    cout << "copy == name? " << (copy == name ? "yes" : "no") << endl;
    cout << "copy == first? " << (copy == first ? "yes" : "no") << endl;

    copy = copy;                        // self-assignment is harmless
    cout << "After copy = copy: "; copy.show();
    return 0;
}
