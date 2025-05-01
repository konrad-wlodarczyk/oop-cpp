#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class NewString : public string
{
    public:
        NewString(const char* word = "default") : string(word) {};
        
        NewString(const string& word = "default") : string(word) {};

        bool contains(const char* str) const
        {
            return this->find(str) != std::string::npos;
        }
        
        int compare(const string& str) const
        {
            std::string thislowercase = *this;
            std::string strlowercase = str;
            
            std::transform(thislowercase.begin(), thislowercase.end(), thislowercase.begin(), ::tolower);
            std::transform(strlowercase.begin(), strlowercase.end(), strlowercase.begin(), ::tolower);
            
            if(thislowercase < strlowercase) return -1;
            if(thislowercase > strlowercase) return 1;
            
            return 0;
        }
};

int main()
{
    
    NewString string1("Fajny Świecki Kanał");
    
    const char* str = "Kanał";
    
    if(string1.contains(str))
    {
        cout << str << " has been found in " << string1 << endl;
    }
    else
    {
        cout << str << " has not been found in " << string1 << endl;
    }
    
    NewString string2("irys93"), string3("IrYs93");
    if(string2.compare(string3) == 0)
    {
        cout << string2 << " is the same word as " << string3 << endl;
    }
    else 
    {
        cout << string2 << " is not the same word as " << string3 << endl;
    }
    
    return 0;
}