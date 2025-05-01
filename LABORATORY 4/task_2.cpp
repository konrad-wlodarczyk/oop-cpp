#include <iostream>

using namespace std;

class SmartArray
{
    private:
        int m_length;
        int* m_array;
        
    public:
        //CONSTRUCTOR THAT TAKES LENGTH
        SmartArray(int length) :
            m_length(length)
        {
            m_array = new int[length]();
        }
        
        //DEEP COPY CONSTRUCTOR
        SmartArray(const SmartArray& other) :
            m_length(other.m_length)
        {
            m_array = new int[m_length];
            
            for(int i = 0; i < m_length; i++)
            {
                m_array[i] = other.m_array[i];
            }
            
            cout << "Deep copy constructor called!" << endl;
        }
        
        //DESTRUCTOR
        ~SmartArray()
        {
            delete[] m_array;
        }
        
        //OVERLOADING SUBSCRIPT OPERATOR
        int& operator[] (const int index);
        
        //OVERLOADING ASSIGNMENT OPERATOR
        SmartArray& operator=(const SmartArray& other)
        {
            delete[] m_array;
            
            m_length = other.m_length;
            m_array = new int[m_length];
            
            for(int i = 0; i < m_length; i++)
            {
                other.m_array[i] = m_array[i];
            }
        }
        
        //OVERLOADING THE OUTPUT OPERATOR
        friend ostream& operator<<(ostream& out, const SmartArray& a);
};

int& SmartArray::operator[] (const int index)
{
    return m_array[index];
}

ostream& operator<<(ostream& out, const SmartArray& a)
{
    for(int i = 0; i < a.m_length; i++)
    {
        cout << "Value of index nr [ " << i << "]: " << a.m_array[i] << endl;
    }
    
    return out;
}

int main(){
    
    SmartArray array1(3);
    array1[0] = 5;
    array1[1] = 2;
    array1[2] = 3;
    
    cout << "First array: \n" << array1 << endl;
    
    //CREATING A COPY
    SmartArray copy(array1);
    
    cout << "\nThe copied array: \n" << copy << endl;
    
    //ASSIGNING THE VALUE TO ANOTHER ARRAY
    SmartArray array2 = array1;
    
    cout << "\nSecond array with assigned value of array1: \n" << array2 << endl;
    
    
    return 0;
}