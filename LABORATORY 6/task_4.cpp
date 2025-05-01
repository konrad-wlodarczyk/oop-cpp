#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

int main()
{
    string filename = "example.txt";
    std::ifstream file;
    
    //THE EXCEPTION IS THROWN AT THE END DUE TO EOF BECAUSE OF THE ifstream::failbit. 
    //IF WE DELETE IT THERE IS NO EXCEPTION :)
    file.exceptions(ifstream::failbit|ifstream::badbit);
    
    try
    {
        
        file.open(filename);
    
        char character;
    
        while(file.get(character))
        {
            cout << character << "\n";
        }
    
        file.close();
    
    }catch(const ifstream::failure& e){
        
        cerr << "\nException: " << e.what();
    }
    
    return 0;
}