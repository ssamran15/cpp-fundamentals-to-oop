// P19.4: An array of Book objects built with a member initializer list
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    double price;

public:
    Book(string t, string a, double p) : title(t), author(a), price(p)
    {
    }

    void show()
    {
        cout << title << " by " << author << ", Rs. " << price << endl;
    }
};

int main()
{
    Book list[3] = { Book("Computer Science Made Easy", "Ahmad Raza", 950),
                     Book("Learning Databases", "Hina Tariq", 1200),
                     Book("Networks for Beginners", "Usman Ali", 780) };

    for (int i = 0; i < 3; i++)
        list[i].show();
    return 0;
}
