// P31.3: minMax with a specialisation for C-strings
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

template <typename T>
void minMax(const T a[], int n, T &smallest, T &largest)
{
    smallest = largest = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < smallest) smallest = a[i];
        if (largest < a[i]) largest = a[i];
    }
}

// For C-strings, < would compare addresses, so this version compares the text
template <>
void minMax<const char *>(const char * const a[], int n, const char * &smallest, const char * &largest)
{
    smallest = largest = a[0];
    for (int i = 1; i < n; i++)
    {
        if (strcmp(a[i], smallest) < 0) smallest = a[i];
        if (strcmp(a[i], largest) > 0) largest = a[i];
    }
}

int main()
{
    int marks[5] = { 72, 45, 91, 58, 85 };
    int lo, hi;
    minMax(marks, 5, lo, hi);
    cout << "Marks: smallest " << lo << ", largest " << hi << endl;

    string names[4] = { "Sana", "Ali", "Zainab", "Hamza" };
    string first, last;
    minMax(names, 4, first, last);
    cout << "Names: first " << first << ", last " << last << endl;

    const char *cities[4] = { "Okara", "Lahore", "Multan", "Sahiwal" };
    const char *c1, *c2;
    minMax(cities, 4, c1, c2);          // uses the specialisation
    cout << "Cities: first " << c1 << ", last " << c2 << endl;
    return 0;
}
