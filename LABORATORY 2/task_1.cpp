//KONRAD WŁODARCZYK 
//STUDENT ID: 417751
//SUBJECT: OBJECT-ORIENTED PROGRAMMING LANGUAGE

#include <iostream>

using namespace std;

class Point
{
    private:
        float m_x;
        float m_y;
        
    public:
        Point()
        {
            m_x = 0;
            m_y = 0;
        }
        
        const float& getX() const{return m_x;}
        const float& getY() const{return m_y;}
        
        void setX(const float& x) {m_x = x;}
        void setY(const float& y) {m_y = y;}
        
        void print()
        {
            cout << "Point coordinates: (" << m_x << "," << m_y << ")" << endl;
        }
};

int main()
{
    Point point;
    
    point.setX(3.5);
    point.setY(10);
    point.print();

    return 0;
}