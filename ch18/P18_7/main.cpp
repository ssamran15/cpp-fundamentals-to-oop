// P18.7: main.cpp - a program that uses the Book class
#include <iostream>
#include "Book.h"
using namespace std;

int main()
{
    Book b;
    b.setTitle("Computer Science Made Easy");
    b.setAuthor("Ahmad Raza");
    b.setPrice(950);
    b.setCopies(40);
    b.show();

    if (!b.setPrice(0))
        cout << "Price 0 refused" << endl;
    cout << "Price is still Rs. " << b.getPrice() << endl;
    return 0;
}
