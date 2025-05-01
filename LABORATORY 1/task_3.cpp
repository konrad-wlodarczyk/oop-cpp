//KONRAD WŁODARCZYK 
//STUDENT ID: 417751
//SUBJECT: OBJECT-ORIENTED PROGRAMMING LANGUAGE

#include <iostream>

using namespace std;

int main(){
    
    cout << "Basic calculator program used for default operations." << endl;
    
    float number1, number2, result;
    char operation;
    
    cout << "\nType in the first number: ";
    cin >> number1;
    
    cout << "Type in the second number: ";
    cin >> number2;
    
    cout << "Choose arythmetic operation to be done: ";
    cin >> operation;
    
    switch(operation)
    {
        case '+':
        {
            result = number1 + number2;
             cout << "The result of addition: " << result;
            break;
        }
        case '-':
        {
            result = number1 - number2;
            cout << "The result of subtraction: " << result;
            break;
        }
        case '*':
        {
            result = number1 * number2;
            cout << "The result of multiplication: " << result;
            break;
        }
        case '/':
        {
            if(number2 == 0)
            {
                cout << "You cannot divide by 0!" << endl;
                break;
            }
            
            result = number1/number2;
            cout << "The result of division: "<< result;
            break;
        }
    }
        
    return 0;
            
}
