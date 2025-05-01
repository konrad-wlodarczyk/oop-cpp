#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
    private:
        int m_numerator;
        int m_denominator;
        
    public:
        
        //CONSTRUCTOR THAT TAKES VALUES
        Fraction(int numerator = 0, int denominator = 1) :
            m_numerator(numerator), m_denominator(denominator)
        {
            assert(denominator != 0);
        }
        
        //COPY CONSTRUCTOR
        Fraction(const Fraction& fraction):
            m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
        {
            cout << "Copy constructor called!" << endl; //PROVING THE COPY CONSTRUCTOR WORKS
        }
        
        //SETTERS
        void setNumerator(const int& numerator) {m_numerator = numerator;}
        void setDenominator(const int& denominator) {m_denominator = denominator;}
        
        //GETTERS
        const int& getNumerator() const{return m_numerator;}
        const int& getDenominator() const{return m_denominator;}
        
        //OVERLOADED << AND >> OPERATORS
        friend ostream& operator<<(ostream& out, const Fraction& f1);
        friend istream& operator>>(istream& in, Fraction& f1);
        
        //OVERLOADING THE INCREMENTOR OPERATORS
        Fraction& operator++(); //PREINCREMENT
        Fraction operator++(int); //POSTINCREMENTOR
        
        Fraction& operator=(const Fraction& f1)
        {
            m_numerator = f1.m_numerator;
            m_denominator = f1.m_denominator;
            
            return *this;
        }
        
        //TYPE CAST OPERATOR TO DOUBLE
        
        operator double() const
        {
            return static_cast<double>(m_numerator) / m_denominator;
        }
};



Fraction& Fraction::operator++()
{
    ++m_numerator;
    
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp(m_numerator, m_denominator);
    
    ++(*this);
    
    return temp;
}

ostream& operator<<(ostream& out, const Fraction& f1)
{
    out << f1.m_numerator << "/" << f1.m_denominator;
    return out;
}

istream& operator>>(istream& in, Fraction& f1)
{
    int numerator, denominator;
    
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;
    
    f1.setNumerator(numerator);
    f1.setDenominator(denominator);
    
    return in;
}

int main()
{
    
    Fraction FiveThirds(5, 3);
    
    Fraction fCopy(FiveThirds);
    cout << fCopy << endl;
    
    Fraction A;
    cin >> A;
    cout << "Fraction A: " << A << endl;
    
    //ASSIGNING VALUE OF FIVETHIRDS TO A
    A = FiveThirds;
    
    cout << "\nA after assigning FiveThirds to it: " << A << endl;
    
    cout << "Value after preincrementing: " << ++A << endl;
    
    cout << "Value after postincrementing: " << A++ << endl;
    
    cout << "Subsequent value of A after postincrement: " << A << endl;
    
    double B = A;
    
    cout << "Value of A in type double: " << B << endl;
    

    return 0;
}