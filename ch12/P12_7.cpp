// P12.7: A Book structure
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Book
{
    string title;
    string author;
    double price;
    int copies;
};

int main()
{
    Book b;
    cout << "Title: ";
    getline(cin, b.title);
    cout << "Author: ";
    getline(cin, b.author);
    cout << "Price: ";
    cin >> b.price;
    cout << "Copies: ";
    cin >> b.copies;

    cout << fixed << setprecision(2);
    cout << endl << "Book details" << endl;
    cout << "Title  : " << b.title << endl;
    cout << "Author : " << b.author << endl;
    cout << "Price  : Rs. " << b.price << endl;
    cout << "Copies : " << b.copies << endl;
    cout << "Stock value: Rs. " << b.price * b.copies << endl;
    return 0;
}
