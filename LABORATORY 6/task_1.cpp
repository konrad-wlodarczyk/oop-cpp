#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

void QuadraticFunction(double a, double b, double c, double &x1, double &x2)
{
    double delta = (pow(b, 2)) - (4*a*c);
    
    if(delta < 0)
    {
        throw runtime_error("Equation has no real solutions.");
        cout << "\nThis never prints";
    }
    
    else if(delta == 0)
    {
        x1 = x2 = (-b - sqrt(delta))/(2*a);
        
        cout << "\nThe solution of the equation: " << x1;
    }
    else
    {
        x1 = (-b - sqrt(delta))/(2*a);
        x2 = (-b + sqrt(delta))/(2*a);
        
        cout << "\nThe solutions of the equation: " << x1 << ", " << x2;
    }
    
};

int main()
{
    double a, b, c;
    
    cout << "PROGRAM USED FOR CALCULATING THE SOLUTION OF QUADRATIC EQUATION: a^2x + bx + c";
    cout << "\nINPUT THE A, B AND C PARAMETERS: \nA: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
    cout << "C: ";
    cin >> c;
    
    cout << "\nQUADRATIC EQUATION: " << a << "^2x + " << b << "x + " << c; 
    
    try
    {
        double x1, x2;
        QuadraticFunction(a, b, c, x1, x2);
    }
    catch(const runtime_error& error)
    {
       cout << "Caught an exception: " << error.what();
       throw invalid_argument("Equation has no real solutions.");
    }
    catch(...)
    {
        cout << "\nCaught an exception of undetermined type.";
    }


    
    return 0;
}