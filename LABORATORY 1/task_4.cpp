//KONRAD WŁODARCZYK 
//STUDENT ID: 417751
//SUBJECT: OBJECT-ORIENTED PROGRAMMING LANGUAGE

#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    
    srand(time(NULL));
    
    const int quantity = 5; 
    const int range = 50;
    
    set<int> GeneratedNumbers;
    int numbers[quantity];
    
    int i = 0;
    while(i < quantity)
    {
        int value = rand()%range + 1;
        
        if(GeneratedNumbers.insert(value).second)
        {
            numbers[i] = value;
            i++;
        }
    }
    
     for(i = 0; i < quantity; i++)
    {
        cout << "Number " << i + 1 << ": " << numbers[i] << endl;
    }

    return 0;
}
