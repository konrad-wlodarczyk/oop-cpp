//KONRAD WŁODARCZYK 
//STUDENT ID: 417751
//SUBJECT: OBJECT-ORIENTED PROGRAMMING LANGUAGE

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(){
    
    cout << "Welcome to my guessing game!\nYour task will be to guess which number between 1 and 100 was randomly chosen by the program.\nYou have 8 tries, good luck :)" << endl;
    
    srand(time(NULL)); 
    
    int random = 1 + rand()%100, guess;
    
    for(int i = 0; i < 8; i++)
    {
        cout << "\nGuess number " << i+1 << ": ";
        cin >> guess;
        
        if(guess < 0 || guess > 100)
        {
            cout << "Your guessed number is out of the defined range." << endl;
        }
        else if(guess == random)
        {
            cout << "\nCongratulations! Your intuition is outstanding!";
            break;
        }
        else if(guess < random)
        {
            cout << "Not this time... Guess higher :)" << endl;
        }
        else if(guess > random)
        {
            cout << "Not this time... Guess lower :)" << endl;
        }
        
        if(i == 7)
        {
            cout << "Out of tries! Better luck next time :)";
        }
    }
    
    return 0;
}
