#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class Time
{
    private:
        int m_hours;
        int m_minutes; 
        int m_seconds;
        
    public:
        //CONSTRUCTOR THAT TAKES THE VALUES
        Time(int hours, int minutes, int seconds) : 
            m_hours(hours), m_minutes(minutes), m_seconds(seconds)
        {
            assert(hours < 24 && minutes < 60 && seconds < 60);
        }
        
        //SETTERS
        void setHours(const int& hours) {assert(hours < 24); m_hours = hours;}
        void setMinutes(const int& minutes) {assert(minutes < 60); m_minutes = minutes;}
        void setSeconds(const int& seconds) {assert(seconds < 60); m_seconds = seconds;}
        
        //GETTERS
        const int& getHours() const{return m_hours;}
        const int& getMinutes() const{return m_minutes;}
        const int& getSeconds() const{return m_seconds;}
        
        //METHOD TO PRINT TIME
        
        void printTime()
        {
            cout << "The Time [hours:minutes:seconds]: " << setfill('0') << setw(2) << m_hours
                 << ":" << setfill('0') << setw(2) << m_minutes << ":" << setfill('0') << setw(2) << m_seconds << endl;
        }
        
        //OVERLOADING THE + OPERATOR
        
        Time operator+(Time const& other)
        {
            int total_seconds = (m_hours * 3600 + m_minutes * 60 + m_seconds) + 
                                (other.m_hours * 3600 + other.m_minutes * 60 + other.m_seconds);
                                
            return Time(((total_seconds / 3600) % 24), ((total_seconds % 3600) / 60), (total_seconds % 60));
        }
        
        //OVERLOADING THE COMPARE (<) OPERATOR
        
        bool operator<(Time const& other)
        {
            int total_time1 = m_hours * 3600 + m_minutes * 60 + m_seconds;
            int total_time2 = other.m_hours * 3600 + other.m_minutes * 60 + other.m_seconds;
            
            return (total_time1 < total_time2);
        }
        
        bool operator>(Time const& other)
        {
            int total_time1 = m_hours * 3600 + m_minutes * 60 + m_seconds;
            int total_time2 = other.m_hours * 3600 + other.m_minutes * 60 + other.m_seconds;
            
            return (total_time1 > total_time2);
        }
        
        bool operator==(Time const& other)
        {
            int total_time1 = m_hours * 3600 + m_minutes * 60 + m_seconds;
            int total_time2 = other.m_hours * 3600 + other.m_minutes * 60 + other.m_seconds;
            
            return (total_time1 == total_time2);
        }
        
        operator string() const
        {
            stringstream ss;
            
            ss << setfill('0') << setw(2) << m_hours << ":"
               << setfill('0') << setw(2) << m_minutes << ":"
               << setfill('0') << setw(2) << m_seconds;
               
            return ss.str();
        }
};

int main()
{
    Time A(15, 36, 50);
    Time B(15, 36, 50);
    
    A.printTime();
    B.printTime();
    
    //ADDING
    Time C = A + B;
    C.printTime();
    
    //COMPARING
    if(A < B)   cout << "\nThe right hand side time is greater!" << endl;
    if(A > B)   cout << "\nThe left hand side time is greater!" << endl;
    if(A == B)  cout << "\nBoth times are equal to each other!" << endl;
    
    //CONVERTING TO STRING
    string D = C;
    cout << "\nThe time converted into string: " << D << endl;

    return 0;
}