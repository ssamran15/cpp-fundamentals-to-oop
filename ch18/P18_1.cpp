// P18.1: A Book class with checking setters
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    double price;
    int copies;

public:
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }

    bool setPrice(double p)
    {
        if (p <= 0)
            return false;           // refused; the old price is kept
        price = p;
        return true;
    }

    bool setCopies(int c)
    {
        if (c < 0)
            return false;
        copies = c;
        return true;
    }

    string getTitle() { return title; }
    string getAuthor() { return author; }
    double getPrice() { return price; }
    int getCopies() { return copies; }

    void show()
    {
        cout << title << " by " << author << ", Rs. " << price
             << ", " << copies << " copies" << endl;
    }
};

int main()
{
    Book b;
    b.setTitle("Computer Science Made Easy");
    b.setAuthor("Ahmad Raza");
    b.setPrice(950);
    b.setCopies(40);
    b.show();

    if (!b.setPrice(-200))
        cout << "Price -200 refused" << endl;
    if (!b.setCopies(-5))
        cout << "Copies -5 refused" << endl;

    b.setPrice(875);
    cout << "Using the getters: " << b.getTitle() << " / " << b.getAuthor()
         << " / Rs. " << b.getPrice() << " / " << b.getCopies() << " copies" << endl;
    return 0;
}
