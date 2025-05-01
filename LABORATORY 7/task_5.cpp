#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int linenumber = 1;
    map<string, vector<int>> lines;
    
    string word;
    
    while(true)
    {
        cout << "Please type in the word (or end if you want to finish): ";
        getline(cin, word);
        
        if(word == "end")
        {
            cout << "Finished!";
            break;
        }
        
        lines[word].push_back(linenumber);
        
        linenumber++;
    }
    
    cout << "\nWord lines number: " << endl;
    for(const auto& pair : lines)
    {
        cout << pair.first << " => ";
        
        for(size_t i = 0; i < pair.second.size(); i++)
        {
            cout << pair.second[i];
            
            if(i < pair.second.size())
            {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}