// P12.5: Replacing a word in a sentence
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence, oldWord, newWord;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    cout << "Word to replace: ";
    getline(cin, oldWord);
    cout << "Replace with: ";
    getline(cin, newWord);

    int count = 0;
    size_t pos = sentence.find(oldWord);
    while (pos != string::npos)
    {
        sentence.replace(pos, oldWord.length(), newWord);
        count++;
        pos = sentence.find(oldWord, pos + newWord.length());   // continue after the new word
    }
    cout << "Result: " << sentence << endl;
    cout << count << " replacement(s) made" << endl;
    return 0;
}
