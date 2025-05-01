#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

int main()
{
    string word; 
    
    cout << "Please write in a string: ";
    getline(cin, word);
    
    
    try{
        int i_string = std::stoi(word);
    
        cout << "After converting the string into an int: " << i_string;
    
        std::stringstream ss;
        ss << std::hex << i_string;
        string hex = ss.str();
    
        cout << "\nAfter converting the int into a string in hex format: " << hex;
    }catch(const std::invalid_argument& e){
        
        cerr << "Error: Caught an exception of invalid_argument type.";
        
    }catch(const std::out_of_range& e){
        
        cerr << "Error: Caught an exception of out_of_range type.";
    }catch(...){
        
        cerr << "Error: Caught an exception of unknown type.";
    }
    return 0;
}