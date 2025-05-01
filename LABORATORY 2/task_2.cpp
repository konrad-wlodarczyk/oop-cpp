//KONRAD WŁODARCZYK 
//STUDENT ID: 417751
//SUBJECT: OBJECT-ORIENTED PROGRAMMING LANGUAGE

#include <iostream>

using namespace std;

class Rectangle
{
    private:
        //BOTTOM LEFT CORNER
        float m_x;
        float m_y;
        
        float m_width;
        float m_height;
        
    public:
        //DEFAULT CONSTRUCTOR
        Rectangle()
        {
            m_x = 0;
            m_y = 0;

            m_width = 0;
            m_height = 0;
        }
        
        //GETTERS FOR POINT COORDINATES, WIDTH AND HEIGHT
        const float& getX() const{return m_x;}
        const float& getY() const{return m_y;}
        const float& getHeight() const{return m_height;}
        const float& getWidth() const{return m_width;}
        
        //AREA AND PERIMETHER FUNCTIONS
        const float getArea() const{return (m_height*m_width);}
        const float getPerimether() const{return (2*m_height + 2*m_width);}
        
        //SETTER
        void setX(const float& x){m_x = x;}
        void setY(const float& y){m_y = y;}
        void setHeight(const float& height){m_height = height;}
        void setWidth(const float& width){m_width = width;}
        
        //FUNCTION FOR MOVING THE RECTANGLE
        void move(float dx, float dy)
        {
            m_x += dx;
            m_y += dy;
        }
        
        //PRINTING FUNCTION
        void print()
        {
           cout << "\nArea of the rectangle: " << getArea() << endl;
           cout << "Perimether of the rectangle: " << getPerimether() << endl;
           cout << "Point 1: (" << m_x << "," << m_y << ")" << endl;
           cout << "Point 2: (" << m_x + m_width << "," << m_y << ")" << endl;
           cout << "Point 3: (" << m_x + m_width << "," << m_y + m_height << ")" << endl;
           cout << "Point 4: (" << m_x << "," << m_y + m_height << ")" << endl;
        }
};

int main()
{
    
    cout << "\nRectangle point number distribution:"
                    "\n                                    "
                    "\n   4-----------------3              "
                    "\n   |                 |              "
                    "\n   |                 |              "
                    "\n   |                 |              "
                    "\n   1-----------------2              "
                    "\n                                     " << endl;
                    
    Rectangle rectangle;
    
    //FIRST RECTANGLE
    rectangle.setX(1);
    rectangle.setY(2);
    rectangle.setHeight(5);
    rectangle.setWidth(5);
    rectangle.print();
    
    //MODIFYING THE HEIGHT AND WIDTH USING SETTERS
    rectangle.setHeight(6);
    rectangle.setWidth(3);
    rectangle.print();
    
    //TESTING THE MOVING FUNCTION
    rectangle.move(1, 3);
    rectangle.print();
    
    return 0;
}