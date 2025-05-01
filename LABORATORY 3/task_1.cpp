#include <iostream>
#include <cassert>

using namespace std;

class Rational
{
    private:
        int m_numerator;
        int m_denominator;
        
    public:
        Rational(int numerator = 0, int denominator = 1)
        {
            assert(denominator != 0);
            m_denominator = denominator;
            m_numerator = numerator;
        }
        
        const int& getNumerator() const{return m_numerator;}
        const int& getDenominator() const{return m_denominator;}
        float getValue() const{return static_cast<float>(m_numerator)/m_denominator;}
        
        void setNumerator(const int& numerator) {m_numerator = numerator;}
        void setDenominator(const int& denominator) {m_denominator = denominator;}
        
        friend ostream& operator<<(ostream& out, Rational& Fraction);
        friend istream& operator>>(istream& in, Rational& Fraction);
        
         //ADDITION
        Rational operator+(Rational const& second)
        {
            int new_numerator = m_numerator * second.m_denominator + second.m_numerator * m_denominator;
            int new_denominator = m_denominator * second.m_denominator;
            
            return Rational(new_numerator, new_denominator);
        }
        
        //SUBTRACTION
        Rational operator-(Rational const& second)
        {
            int new_numerator = m_numerator * second.m_denominator - second.m_numerator * m_denominator;
            int new_denominator = m_denominator * second.m_denominator;
            
            return Rational(new_numerator, new_denominator);
        }
        
        //MULTIPLICATION
        Rational operator*(Rational const& second)
        {
            int new_numerator = m_numerator * second.m_numerator;
            int new_denominator = m_denominator * second.m_denominator;
            
            return Rational(new_numerator, new_denominator);
        }
        
        //DIVISION
        Rational operator/(Rational const& second)
        {
            int new_numerator = m_numerator * second.m_denominator;
            int new_denominator = m_denominator * second.m_numerator;
            
            return Rational(new_numerator, new_denominator);
        }
        
        bool operator==(Rational const& second)
        {
            return (m_numerator * second.m_denominator == m_denominator * second.m_numerator);
        }
        
        bool operator!=(Rational const& second)
        {
            return !(m_numerator * second.m_denominator == m_denominator * second.m_numerator);
        }
        
        bool operator>(Rational const& second)
        {
            return (m_numerator * second.m_denominator > m_denominator * second.m_numerator);
        }
        
        bool operator<(Rational const& second)
        {
            return (m_numerator * second.m_denominator < m_denominator * second.m_numerator);
        }
};

ostream& operator<<(ostream& out, Rational& Fraction)
{
    out << Fraction.m_numerator << "/" << Fraction.m_denominator;
    return out;

};

istream& operator>>(istream& in, Rational& Fraction)
{
    int numerator, denominator;
            
    cout << "\nEnter numerator: ";
    in >>  numerator;
    cout << "Enter denominator: ";
    in >> denominator;
            
    Fraction.setNumerator(numerator);
    Fraction.setDenominator(denominator);
            
    return in;
};

int main()
{
    Rational A, B;
    
    //ENTERING THE FIRST FRACTION
    cin >> A;
    cout << "Fraction: " << A << endl;
    
    //ENTERING THE SECOND FRACTION
    cin >> B;
    cout << "Fraction: " << B << endl;
    
    //ADDITION
    Rational addition = A + B;
    cout << "Result of addition: " << addition << " = " << addition.getValue() << endl;
    
    //SUBTRACTION
    Rational subtraction = A - B;
    cout << "Result of subtraction: " << subtraction << " = " << subtraction.getValue() << endl;
   
    //MULTIPLICATION 
    Rational multiplication = A * B;
    cout << "Result of multiplication: " << multiplication << " = " << multiplication.getValue() << endl;
    
    //DIVISION
    Rational division = A / B;
    cout << "Result of division: " << division << " = " << division.getValue() << endl;
    
    //COMPARISON 1
    if(A == B) cout << "\nBoth of the fractions are equal" << endl;
    
    //COMPARISON 2
    if(A != B) cout << "\nBoth of the fractions are different" << endl;
    
    //COMPARISON 3
    if(A > B) cout << "\nThe left hand side fraction is greater" << endl;
    
    //COMPARISON 4
    if(A < B) cout << "\nThe right hand side fraction is greater" << endl;
 

    return 0;
}