//KONRAD WŁODARCZYK 
//STUDENT ID: 417751
//SUBJECT: OBJECT-ORIENTED PROGRAMMING LANGUAGE

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
 
int main()
{
    string word;
    
    cout << "Type in the string to be used: ";
    cin >> word; 
    
    sort(word.begin(), word.end());
    
    int i = 1;
    
    do
    {
        cout << "Permutation number [" << i << "]: " << word << '\n';
        i++;
    }
    while (std::next_permutation(word.begin(), word.end()));
}
