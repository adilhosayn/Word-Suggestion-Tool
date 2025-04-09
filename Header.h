#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;
// thism method returns true if the "word" is present in the vector "dict", else returns a false
class SpellChecker 
{
    public:
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
    // this method returns true if the "word" starts with the "firstTwoLetters", else returns false
    bool checkFirstTwoLetters(string word, string firstTwoLetters)
    {
    stringstream ss;
    ss << word[0] << "" << word[1];
    string resTwoLetters = ss.str();
    if (resTwoLetters.compare(firstTwoLetters) == 0)
    return true;
    else
    return false;
    }
    // this method returns a list containing all those word from "dict" which starts with the first two letters from //the "word"
    vector<string> giveSuggestions(vector<string> dict, string word)
    {
    vector<string> suggestions;
    // take the first 2 letters of the word
    stringstream ss;
    ss << word[0] << "" << word[1];
    string firstTwoLetters = ss.str();
    // get all the words having the above first two letters
    for (string w : dict)
    {
    if (w.compare(word) != 0 && checkFirstTwoLetters(w, firstTwoLetters))
    suggestions.push_back(w);
    }
    return suggestions;
    }
};