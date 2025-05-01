//KONRAD WŁODARCZYK 
//STUDENT ID: 417751
//SUBJECT: OBJECT-ORIENTED PROGRAMMING LANGUAGE

#include <iostream>
#include <string>

using namespace std;

int main()
{
  cout << "Program that creates a hollow equilateral triangle\nout of an input word given by the user." << endl;
  string word;
  cout << "\nWrite in the word you want to use: ";
  cin >> word;
  
  int length = word.length();

  int temp = length;
    
   for(int i = 0; i<=length;i++)
   {
       
         if(i == length-1)
            {
            for(int l = length; l>=0; l--)
            {
                cout << word[l];
            }
            for(int l = 1; l<=length; l++)
            {
                cout<<word[l];
            }
            cout << endl;
            break;
        }

        for(int j = temp-1; j>0; j--){
            cout << " ";
        }
        cout << word[i];

        
        if(i>0){

            for(int k = 2; k <= (length - temp) + i; k++){
                cout << " ";
            }
            
            cout << word[i];
        }
        temp--;
        cout << endl;
    }
    
    return 0;
}