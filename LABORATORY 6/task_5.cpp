#include <iostream>
#include <stdexcept>

using namespace std;

class OutOfRangeException : public std::exception
{
    public:
        const char* what() const noexcept{
            
            return "A mark should be between 0 and 100";
        }
};

float calculateAverage(int mark1, int mark2, int mark3, int mark4)
{
    
    /**
     * SPECIFICATION OF THE FUNCTION:
     * 
     * PRE-CONDITIONS:
     * Marks 1 through 4 represent four marks from which an average will be calculated.
     * The value of marks must be of integer type with value between 0 and 100 including the limits.
     * 
     * POST-CONDITIONS:
     * The function returns the average value of type float calculated from the four marks specified
     * in the input.
     * 
     * INVARIANTS:
     * The average value should be a float that is the total sum of the marks divided by four.
     * 
     * EXCEPTIONS:
     * If any marks are outside of the predefined (<0 ; 100>) range, an OutOfRange exception is thrown.
     * 
     * EXAMPLE OF USAGE:
     * VALID:
     * 
     * calculateAverage(80, 50, 43, 31)
     * Average value: 51
     * 
     * INVALID:
     * 
     * calculateAverage(-10, 110, 50, 50)
     * the OutOfRange exception is thrown.
    */
    
    int marks[] = {mark1, mark2, mark3, mark4};
    
    for(int i = 0; i < 4; i++)
    {
        if(marks[i] < 0 || marks[i] > 100)
        {
            throw OutOfRangeException();
        }
    }
    
    return static_cast<float>(mark1 + mark2 + mark3 + mark4) / 4.0f;
};

int main()
{
    try
    {
        //EXAMPLE WITH VALID MARKS
        float average1 = calculateAverage(80, 50, 43, 31);
        cout << "Average value: " << average1;
        
        //EXAMPLE WITH MARK OUT OF RANGE
        float average2 = calculateAverage(-10, 110, 50, 50);
        cout << "\nAverage value: " << average2;
    }catch(const OutOfRangeException& e){
        
        cerr << "\nException caught: " << e.what();
        
    }
    
    return 0;
}