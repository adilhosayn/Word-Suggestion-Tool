#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// Trims leading and trailing whitespace from a string
string trim(const string &str)
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

// This method returns true if the "word" is present in the vector "dict", else returns false
bool isWordPresentInDictionary(vector<string> dict, string word)
{
    bool found = false;
    for (string w : dict)
    {
        if (w.compare(word) == 0)
        {
            found = true;
            break;
        }
    }
    return found;
}

// This method returns true if the "word" starts with the "firstTwoLetters", else returns false
bool checkFirstThreeLetters(string word, string firstThreeLetters)
{
    if (word.length() < 3)
        return false; // Avoid out-of-range error
    string resThreeLetters = word.substr(0, 3);
    return resThreeLetters.compare(firstThreeLetters) == 0;
}

// This method returns a list containing all those words from "dict" which start with the first two letters of "word"
vector<string> giveSuggestions(vector<string> dict, string word)
{
    vector<string> suggestions;
    if (word.length() < 2)
        return suggestions; // No suggestions if word is too short
    string firstThreeLetters = word.substr(0, 3);
    for (string w : dict)
    {
        if (w.compare(word) != 0 && checkFirstThreeLetters(w, firstThreeLetters))
            suggestions.push_back(w);
    }
    return suggestions;
}

int main()
{
    string filename = "Dictionary.txt";
    ifstream inFile(filename.c_str());
    string line;
    vector<string> dictionaryWords;

    // Check if input file is good to open
    if (!inFile.is_open())
    {
        cout << "Error in opening file " << filename << "! Exiting..\n";
        exit(EXIT_FAILURE);
    }

    // Read file line-by-line and push trimmed words into dictionaryWords
    while (getline(inFile, line))
    {
        dictionaryWords.push_back(trim(line));
    }
    inFile.close();

    // Prompt user to enter a word
    cout << "Please enter a word: ";
    string userWord;
    cin >> userWord;
    userWord = trim(userWord);

    bool wordFoundStatus = isWordPresentInDictionary(dictionaryWords, userWord);
    if (!wordFoundStatus)
    {
        // Returning false, exit the program
        cout << "There is no word as " << userWord << " in the dictionary!\n";
        exit(EXIT_SUCCESS);
    }

    // Returning true, give user word suggestions
    vector<string> suggestions = giveSuggestions(dictionaryWords, userWord);
    cout << "More suggestions are:\n";
    for (string w : suggestions)
        cout << w << endl;

    cout << endl;
    return 0;
}