//KONRAD WŁODARCZYK 
//STUDENT ID: 417751
//SUBJECT: OBJECT-ORIENTED PROGRAMMING LANGUAGE

#include <iostream>
#include <string>

using namespace std;

class Student
{
    private:
        string m_name;
        unsigned int m_id;
        float m_grade;
        
    public:
        //DEFAULT CONSTRUCTOR
        Student()
        {
            m_name = "default";
            m_id = 0;
            m_grade = 0;
        }
        
        //GETTER, RETURN BY CONSTANT REFERENCE
        const string& getName() const{return m_name;}
        const unsigned int& getID() const{return m_id;}
        const float& getGrade() const{return m_grade;}
        
        //SETTER, PASS THE OBJECT AS A CONSTANT REFERENCE
        void setName(const string& name) {m_name = name;}
        void setID(const float& id) {m_id = id;}
        void setGrade(const float& grade) {m_grade = grade;}
        
        //PRINT METHOD
        void print()
        {
            cout << "\nName: " << m_name << "\nID: " << m_id << "\nGrade: " << m_grade << endl;
        }
    
};

int main()
{
    Student JohnMarston, DioBrando, ElvisPresley;
    
    JohnMarston.setName("John");
    JohnMarston.setID(1234);
    JohnMarston.setGrade(2.63);
    JohnMarston.print();
    
    DioBrando.setName("Dio");
    DioBrando.setID(9999);
    DioBrando.setGrade(5.0);
    DioBrando.print();
    
    ElvisPresley.setName("Elvis");
    ElvisPresley.setID(5678);
    ElvisPresley.setGrade(3.79);
    ElvisPresley.print();
    
    float average = (JohnMarston.getGrade() + DioBrando.getGrade() + ElvisPresley.getGrade()) / 3;

    cout << "\nThe average grade of all students: " << average << endl;
    return 0;
}