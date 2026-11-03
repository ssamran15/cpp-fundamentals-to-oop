// P12.2: How many times a word appears
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence, word;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    cout << "Enter a word: ";
    getline(cin, word);

    int count = 0;
    size_t pos = sentence.find(word);            // size_t is the type that find returns
    while (pos != string::npos)
    {
        count++;
        pos = sentence.find(word, pos + word.length());   // search again after this match
    }
    cout << "\"" << word << "\" appears " << count << " time(s)" << endl;
    return 0;
}
