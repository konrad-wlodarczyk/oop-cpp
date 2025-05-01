//KONRAD WŁODARCZYK 
//STUDENT ID: 417751
//SUBJECT: OBJECT-ORIENTED PROGRAMMING LANGUAGE

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    
    cout << "Program used for printing backwards the string written by the user." << endl;
    
    string word;
    
    cout << "\nType in the string to be reversed: ";
    getline(cin, word);
    reverse(word.begin(), word.end());
    
    cout << "\nThe reversed string: " << word << endl;
    
    return 0;
}
