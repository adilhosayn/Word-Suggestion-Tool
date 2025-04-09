#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;
// thism method returns true if the "word" is present in the vector "dict", else returns a false
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
int main()
{
string filename = "Dictionary1.txt";
ifstream inFile(filename.c_str());
string line;
vector<string> dictionaryWords;
// check if input file is good to open
if (!inFile.is_open())
{
cout << "Error in opening file " << filename << "! Exiting..\n";
exit(EXIT_FAILURE);
}
// read file line-by-line and pushes the words into the list/vector "dictionaryWords"
while (getline(inFile, line))
{
dictionaryWords.push_back(line);
}
inFile.close();
// prompt user to enter a word
cout << "Please enter a word: ";
string userWord;
cin >> userWord;
bool wordFoundStatus = isWordPresentInDictionary(dictionaryWords, userWord);
if (!wordFoundStatus)
{
// returning false, exit the program
cout << "There is no word as " << userWord << " in the dictionary!\n";
exit(EXIT_SUCCESS);
}
// returning true, give user word suggestions
vector<string> suggestions = giveSuggestions(dictionaryWords, userWord);
cout << "More suggestions are:\n";
for (string w : suggestions)
cout << w << endl;
cout << endl;
return 0;
}
