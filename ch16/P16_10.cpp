// P16.10: Showing a file with line numbers
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage: P16_10 filename" << endl;
        return EXIT_FAILURE;
    }

    ifstream in(argv[1]);
    if (!in)
    {
        cout << "Cannot open " << argv[1] << endl;
        return EXIT_FAILURE;
    }

    string line;
    int number = 0;
    while (getline(in, line))
        cout << ++number << ": " << line << endl;
    in.close();
    return EXIT_SUCCESS;
}
