// P11.7: Counting words in a sentence
#include <iostream>
using namespace std;

int main()
{
    char text[200];
    cout << "Enter a sentence: ";
    cin.getline(text, 200);

    int words = 0;
    if (text[0] != '\0')
    {
        words = 1;                       // a non-empty sentence has at least one word
        for (int i = 0; text[i] != '\0'; i++)
            if (text[i] == ' ')
                words++;                 // each space starts one more word
    }
    cout << "Number of words: " << words << endl;
    return 0;
}
