#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main()
{
    string word;
    cout << "Please write in a string in order to check the frequency of each letter: ";
    getline(cin, word);
    
    map<char, int> Frequency;
    
    //Counting the frequency of each letter 
    for(char letter : word)
    {
        //Changing each letter to lowercase in order to count better.
        char letterLower = tolower(letter);
        Frequency[letterLower]++;
    }
    
    //Printing the letters with assigned frequency
    cout << "Frequency of letters: ";
    for(const auto& pair : Frequency)
    {
        cout << "\nLetter: " << pair.first << ", Frequency: " << pair.second;
    }

    return 0;
}