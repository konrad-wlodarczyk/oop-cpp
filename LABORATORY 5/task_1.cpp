//I HAVE UPLOADED THE SAME FULL CODE OF THIS EXERCISE WITH EVERY LATTER POINTS
//DONE INTO EACH EXERCISE SLOT, AS WELL AS THE ANSWER ABOUT THE CIRCLE CLASS.
//THE SAME CODE CAN BE FOUND IN EACH TASK SLOT (BESIDES THE SLOT FOR THE NEXT TASK OF 
//COURSE)

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//EXERCISE 1
class MyString : public string
{
        
    public:
        //CONSTRUCTOR WITH DEFAULT VALUE
        MyString(const char* word = "default") : std::string(word)
        {
            cout << "MyString constructor called" << endl;
        }
        
        //DESTRUCTOR
        ~MyString()
        {
            cout << "MyString destructor called" << endl;
        }
        
        friend ostream& operator<<(ostream& out, const MyString& a);
        
        MyString& to_upper()
        {
            for(char& c : *this)
            {
                c = std::toupper(c);
            }
            
            return *this;
        }
};

//EXERCISE 2
class Figure
{
    private:
        float m_x;
        float m_y;
        MyString m_label;
    
    public:
        Figure(float x = 0, float y = 0, const char* label = "default") :
            m_x(x), m_y(y), m_label(label)
        {
            cout << "Figure constructor called" << endl;
        }
        
        ~Figure()
        {
            cout << "Figure destructor called" << endl;
        }
        
        const float& getX() const{return m_x;} 
        const float& getY() const{return m_y;}
        MyString& getLabel() {return m_label;}
        
        void print(void)
        {
            cout << "\nI'm a figure" << endl;
            cout << "Point: " << m_label.to_upper() << ", [x;y]: (" << m_x << ";" << m_y << ")" << endl;  
        }
};

class Rectangle : public Figure
{
    private:
        float m_w;
        float m_h;
    
    
    public:
        Rectangle(double x = 0, double y = 0, double w = 0, double h = 0, const char* label  = "default") : 
            m_w(w), m_h(h), Figure(x, y, label)
        {
            cout << "Rectangle constructor called" << endl;
        }
        
        ~Rectangle()
        {
            cout << "Rectangle destructor called" << endl;
        }
        
        const float& getWidth() const{return m_w;}
        const float& getHeight() const{return m_h;}
        
        void print(void)
        {
            cout << "\nI'm a rectangle!" << endl;
            cout << "Location of " << getLabel().to_upper() << ": (" << getX() << ";" << getY() << ")" << endl;
            cout << "Height: " << m_h << ", Width: " << m_w << endl;
        }
};

class Square : public Rectangle
{
    public:
        Square(double x = 0, double y = 0, double w = 0, const char* label = "default") : 
            Rectangle(x, y, w, w, label)
        {
           cout << "Square constructor called" << endl;
        }
        
        ~Square()
        {
            cout << "Square destructor called" << endl;
        }
        
        void print(void)
        {
            cout << "\nI'm a square!" << endl;
            cout << "Location of " << getLabel().to_upper() << ": (" << getX() << ";" << getY() << ")" << endl;
            cout << "Height/Width: " << getWidth() << endl;
        }
    
};

//IF WE WERE TO CREAT A CIRCLE CLASS IT WOULD BE BEST THAT IT INHERITS FROM THE FIGURE CLASS:
class Circle : public Figure
{
    private:
        double m_radius;
        
    public:
        Circle(double x = 0, double y = 0, double radius = 0, const char* label = "default") :
            Figure(x, y, label), m_radius(radius)
        {
            cout << "Circle constructor called!" << endl;
        }
        
        ~Circle()
        {
            cout << "Circle destructor called!" << endl;
        }
        
        void print(void)
        {
            cout << "\nI'm a circle!" << endl;
            cout << "Location of " << getLabel().to_upper() << ": (" << getX() << ";" << getY() << ")" << endl;
            cout << "Radius: " << m_radius << endl;
        }
    
};

ostream& operator<<(ostream& out, const MyString& a)
{
    out << static_cast<const string &>(a);
    
    return out;
};

int main()
{
    //USING FIGURE CLASS
    //Figure figure1(3.4, 5.6, "Figure 1");
    //figure1.print();
    
    //USING RECTANGLE CLASS
    //Rectangle rectangle1(2.1, 3.7, 10, 5, "Rectangle 1");
    //rectangle1.print();
    
    //USING SQUARE CLASS
    //Square square1(1,  2, 10, "Square 1");
    //square1.print();
    
    //USING CIRCLE CLASS
    Circle circle1(1, 2, 15, "Circle 1");
    circle1.print();
    
    
    return 0;
}