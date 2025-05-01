#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class Complex
{
    private:
        double m_real;
        double m_imaginary;
        
    public:
        Complex(double real = 0, double imaginary = 0)
        {
            m_real = real;
            m_imaginary = imaginary;
        }
    
        const double& getReal() const{return m_real;}
        const double& getImaginary() const{return m_imaginary;}
        
        void setReal(const double& real) {m_real = real;}
        void setImaginary(const double& imaginary) {m_imaginary = imaginary;}
        
        friend istream& operator>>(istream& in, Complex& complex);
        friend ostream& operator<<(ostream& out, Complex& complex);
        
        //ADDITION
        Complex operator+(Complex const& second)
        {
            double new_real = m_real + second.m_real;
            double new_imaginary = m_imaginary + second.m_imaginary;
            
            return Complex(new_real, new_imaginary);
        }
        
        //SUBTRATCTION 
        Complex operator-(Complex const& second)
        {
            double new_real = m_real - second.m_real;
            double new_imaginary = m_imaginary - second.m_imaginary;
            
            return Complex(new_real, new_imaginary);
        }
        
        //MULTIPLICATION
        Complex operator*(Complex const& second)
        {
            double new_real = m_real * second.m_real - m_imaginary * second.m_imaginary;
            double new_imaginary = m_imaginary * second.m_real + m_real * second.m_imaginary;
            
            return Complex(new_real, new_imaginary);
        }
        
        Complex operator/(Complex const& second)
        {
            assert((pow(second.m_real, 2) + pow(second.m_imaginary, 2)) != 0);
            double new_real = ((m_real * second.m_real) + (m_imaginary * second.m_imaginary))/((pow(second.m_real, 2) + pow(second.m_imaginary, 2)));
            double new_imaginary = ((m_imaginary * second.m_real) - (m_real * second.m_imaginary))/((pow(second.m_real, 2) + pow(second.m_imaginary, 2)));
            
            return Complex(new_real, new_imaginary);
        }
        
};

ostream& operator<<(ostream& out, Complex& complex)
{
    if(complex.m_imaginary < 0)
    {
        out << complex.m_real << " " << complex.m_imaginary << "i";
    }
    if(complex.m_imaginary >= 0)
    {
        out << complex.m_real << " + " << complex.m_imaginary << "i";
    }
    
    return out;
};

istream& operator>>(std::istream& in, Complex& complex)
{
    double real, imaginary;
            
    cout << "\nEnter the real part: ";
    in >> real;
    cout << "Enter the imaginary part: ";
    in >> imaginary;
            
    complex.setReal(real);
    complex.setImaginary(imaginary);
            
    return in;
};

int main()
{
    Complex A, B;
    cin >> A;
    cout << "First complex number: " << A << endl;
    cin >> B;
    cout << "Second complex number: " << B << endl;
    
    Complex Addition = A + B;
    cout << "\nResult of addition: " << Addition << endl;
    
    Complex Subtraction = A - B;
    cout << "\nResult of subtraction: " << Subtraction << endl;
    
    Complex Multiplication = A * B;
    cout << "\nResult of multiplication: " << Multiplication << endl;
    
    Complex Division = A / B;
    cout << "\nResult of division: " << Division << endl;

    return 0;
}