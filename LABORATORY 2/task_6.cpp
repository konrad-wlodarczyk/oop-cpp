//KONRAD WŁODARCZYK 
//STUDENT ID: 417751
//SUBJECT: OBJECT-ORIENTED PROGRAMMING LANGUAGE

#include <iostream>
#include <iomanip>

using namespace std;

class Int
{
    private:
        int m_value;
        
    public:
        Int() : m_value(){}
        
        Int(int value) : m_value(value){}
        
        void display(bool Hex = false) const
        {
            if(Hex)
            {
                cout << "Value in hexadecimal format: " << std::hex << m_value << std::dec << endl;
            }
            else
            {
                cout << "Value in decimal format: " << m_value << endl;
            }
        }
        
        int add(const Int& second)
        {
            return int(m_value + second.m_value);
        }

};

int main()
{
  
  Int value1, value2(3), value3(100);
  
  //PLACING THE ADDITION IN THE UNINITIALIZED VARIABLE
  value1 = value2.add(value3);
  
  //DISPLAYING IN DECIMAL
  value1.display();
  
  //DISPLAYING IN HEXADECIMAL
  value1.display(true);
  
  return 0;  
  
};