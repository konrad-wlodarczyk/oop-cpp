#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, string> PhoneBook;
    string name, phonenumber;
    
    while(true)
    {
        cout << "Enter a name (or type exit to quit): ";
        getline(cin, name);
        
        if(name == "exit")
        {
            cout << "\nExiting the program.";
            break;
        }
        
        auto it = PhoneBook.find(name);
    
    if(it != PhoneBook.end())
    {
        cout << "Phone number for: " << name << ":" << it -> second << endl;
    }
    else
    {
        cout << "The name is not present in the phone book, please write in the number: ";
        getline(cin, phonenumber);
        PhoneBook[name] = phonenumber;
    }
    }
    
    return 0;
}