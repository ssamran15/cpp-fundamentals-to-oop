// P16.9: Command-line calculator (compile as calc)
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 4 || strlen(argv[2]) != 1)
    {
        cout << "Usage: calc number1 op number2   (op is +, -, x or /)" << endl;
        return EXIT_FAILURE;
    }

    double a = atof(argv[1]);
    double b = atof(argv[3]);
    char op = argv[2][0];

    switch (op)
    {
        case '+': cout << a + b << endl; break;
        case '-': cout << a - b << endl; break;
        case 'x': cout << a * b << endl; break;
        case '/':
            if (b == 0)
            {
                cout << "Cannot divide by zero" << endl;
                return EXIT_FAILURE;
            }
            cout << a / b << endl;
            break;
        default:
            cout << "Unknown operator " << op << ". Use +, -, x or /" << endl;
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
