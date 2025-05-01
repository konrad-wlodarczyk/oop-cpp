//KONRAD WŁODARCZYK 
//STUDENT ID: 417751
//SUBJECT: OBJECT-ORIENTED PROGRAMMING LANGUAGE

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class SmartArray
{
    private:
        int m_length;
        int* m_array;
    
    public:
        SmartArray(int length)
        {
            m_length = length;
            m_array = new int[length](); 
        }
        
        ~SmartArray()
        {
            delete[] m_array;
        }
        
        const int& getArray(int index) const{return m_array[index];}
        void setArray(int index, const int& value) const{m_array[index] = value;}
        
        void print()
        {
            for(int i = 0; i < m_length; i++)
            {
                cout << "Value under index nr. " << i << ": " << m_array[i] << endl;
            }
        }
        
        void MaxValue()
        {
            int max = *max_element(m_array, m_array + m_length);
            
            cout << "\nMax value of this array = " << max << endl;
        }
        
        void MinValue()
        {
            int min = *min_element(m_array, m_array + m_length);
            cout << "\nMin Value of this array = " << min << endl;
        }
        
        bool IsSorted(int choice)
        {
            if(choice == 1)
            {
            for(int i = 1; i < m_length; i++)
            {
                if(m_array[i-1] > m_array[i])
                {
                    return false;
                }
            }
            
            return true;
            }
            else
            {
               for(int i = 1; i < m_length; i++)
            {
                if(m_array[i-1] < m_array[i])
                {
                    return false;
                }
            }
            
            return true; 
            }
        }
        
        void Sort(int choice)
        {
            if(choice == 1)
            {
                sort(m_array, m_array + m_length);
            }
            else
            {
                sort(m_array, m_array + m_length, greater<int>());
            }
        }
  
};

int main()
{
    //SETTING THE ARRAY FOR USAGE
    SmartArray array(7);
    array.setArray(0, 31);
    array.setArray(1, 26);
    array.setArray(2, 75);
    array.setArray(3, 31);
    array.setArray(4, 26);
    array.setArray(5, 75);
    array.setArray(6, 10);

    //PRINTING THE VALUES OF THE ARRAY 
    array.print();
    
    //CHECKING FOR MAX VALUE
    array.MaxValue();
    
    //CHECKING FOR MIN VALUE
    array.MinValue();
    
    //CHECKING IF THE ARRAY IS SORTED (1 TO CHECK IF SORTED ASCDENGING, 0 IF DESCENDING)
    cout << "\nIs the array sorted? " << (array.IsSorted(1) ? "Yes" : "No") << endl;
    
    //SORTING THE ARRAY (1 FOR ASCENDING, 0 FOR DESCDENGING :))
    array.Sort(1);
    
    //CHECKING ONCE AGAIN IF THE ARRAY IS SORTED
    cout << "\nIs the array sorted? " << (array.IsSorted(1) ? "Yes" : "No") << endl;
    
    //PRINTING THE ARRAY AFTER SORTING
    array.print();

    return 0;
}