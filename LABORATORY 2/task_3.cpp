//KONRAD WŁODARCZYK 
//STUDENT ID: 417751
//SUBJECT: OBJECT-ORIENTED PROGRAMMING LANGUAGE

#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
    private:
        int m_numerator;
        int m_denominator;
        
    public:
        Fraction(int numerator = 0, int denominator = 1)
        {
            assert(denominator != 0);
            m_numerator = numerator;
            m_denominator = denominator;
        }
        
        const int& getNumerator() const{return m_numerator;}
        const int& getDenominator() const{return m_denominator;}
        float getValue() const{return static_cast<float>(m_numerator)/m_denominator;}
        
        void Addition(const Fraction& second)
        {
            int new_numerator = m_numerator * second.m_denominator + second.m_numerator * m_denominator;
            int new_denominator = m_denominator * second.m_denominator;
            
            cout << "The result of addition: " << m_numerator << "/" << m_denominator
            << " + " << second.m_numerator << "/" << second.m_denominator 
            << " = " << new_numerator << "/" << new_denominator << " = " << static_cast<float>(new_numerator)/new_denominator << endl;
        }
        
        void Subtraction(const Fraction& second)
        {
            int new_numerator = m_numerator * second.m_denominator - second.m_numerator * m_denominator;
            int new_denominator = m_denominator * second.m_denominator;
            
            cout << "The result of subtraction: " << m_numerator << "/" << m_denominator
            << " - " << second.m_numerator << "/" << second.m_denominator 
            << " = " << new_numerator << "/" << new_denominator << " = " << static_cast<float>(new_numerator)/new_denominator << endl;
        }
        
        friend void Multiplication(const Fraction& first, const Fraction& second);
        friend void Division(const Fraction& first, const Fraction& second);
};

void Multiplication(const Fraction& first, const Fraction& second)
{
    int new_numerator = first.m_numerator * second.m_numerator;
    int new_denominator = first.m_denominator * second.m_denominator;
    
    cout << "The result of multiplication: " << first.m_numerator << "/" << first.m_denominator
    << " * " << second.m_numerator << "/" << second.m_denominator 
    << " = " << new_numerator << "/" << new_denominator << " = " << static_cast<float>(new_numerator)/new_denominator << endl;
}

void Division(const Fraction& first, const Fraction& second)
{
    int new_numerator = first.m_numerator * second.m_denominator;
    int new_denominator = first.m_denominator * second.m_numerator;
    
    cout << "The result of division: " << first.m_numerator << "/" << first.m_denominator
    << " / " << second.m_numerator << "/" << second.m_denominator 
    << " = " << new_numerator << "/" << new_denominator << " = " << static_cast<float>(new_numerator)/new_denominator << endl;
}

int main()
{
    Fraction A(2, 1);
    Fraction B(5, 1);
    
    //Addition
    A.Addition(B);
    
    //Subtraction
    A.Subtraction(B);
    
    //Multiplication
    Multiplication(A, B);
    
    //Division
    Division(A, B);
    
    
    return 0;
}