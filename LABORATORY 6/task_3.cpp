#include <iostream>
#include <exception>

using namespace std;

class InvalidIndex : public std::exception
{
    public:
        const char* what() const noexcept
        {
            return "Error: Exception of InvalidIndex type happened.";
        }
    
};

class InvalidValue : public std::exception
{
    public:
        const char* what() const noexcept
        {
            return "Error: Exception of InvalidValue type happened.";
        }
    
};

class StaticArray
{
    private:
        int arr[16];
    
    public:
        StaticArray()
        {
            for(int i = 0; i < 16; i++)
            {
                arr[i] = 0;
            }
        }
    
    int at(int index)
    {
        if(index < 0 || index > 16)
        {
            throw InvalidIndex();
        }
        
        return arr[index];
    }
    
    void set_item(int index, int value)
    {
        if(index < 0 || index > 16)
        {
            throw InvalidIndex();
        }
        
        if(value < 0)
        {
            throw InvalidValue();
        }
        
        arr[index] = value;
    }
};

int main()
{
    
    try
    {
        StaticArray array1;
        
        //ASSIGNING VALUE CORRECTLY
        array1.set_item(3, 10);
        array1.set_item(10, 58);
        
        //ASSIGNING VALUE INCORRECTLY
        //array1.set_item(20, 19);
        //array1.set_item(10, -1);
        
    }catch(const InvalidIndex& e){
        
        cerr << e.what();
        
    }catch(const InvalidValue& e){
        
        cerr << e.what();
    }
    
    try
    {
        StaticArray array2;
        
        array2.set_item(15, 69);
        
        //ACCESSING A VALID INDEX
        cout << "Value of the array in index 15: " << array2.at(15);
        
        //ACCESSING AN INVALID INDEX
        cout << "\nValue of the array in index > 16: " << array2.at(21);
    }catch(const InvalidIndex& e){
        
        cerr << e.what();
        
    }
    
    
    return 0;
}