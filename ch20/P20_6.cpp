// P20.6: Our own MyString class
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class MyString
{
private:
    char *text;

public:
    MyString(const char *s)
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

    int length()
    {
        return strlen(text);
    }

    void show()
    {
        cout << text << endl;
    }

    void toUpper()
    {
        for (int i = 0; text[i] != '\0'; i++)
            text[i] = toupper(text[i]);
    }
};

int main()
{
    MyString city("Okara");
    MyString copy = city;

    copy.toUpper();
    cout << "city: "; city.show();
    cout << "copy: "; copy.show();
    cout << "Length: " << city.length() << endl;
    return 0;
}
