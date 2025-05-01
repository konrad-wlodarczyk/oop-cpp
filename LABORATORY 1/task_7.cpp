//KONRAD WŁODARCZYK 
//STUDENT ID: 417751
//SUBJECT: OBJECT-ORIENTED PROGRAMMING LANGUAGE

#include <iostream>

using namespace std;

class Stack
{
    private:
        int* memory; //DYNAMIC ARRAY TO STORE STACK DATA
        int top;
        int m_capacity;
        
    public:
        //CONSTRUCTOR WITH SIZE INITIALIZATION
        Stack(int capacity)
        {
            m_capacity = capacity;
            memory = new int[capacity]();
            top = -1; 
        }
        
        //DESTRUCTOR
        ~Stack()
        {
            delete[] memory;
        }
        
        void push(int data)
        {
            if(top == m_capacity - 1)
            {
                cout << "Stack Overflow! Cannot push element, out of memory." << endl;
            }
            else
            {
                memory[++top] = data;
            
                cout << "Data pushed to the stack: " << data << endl;
            }
        }
        
        void pop()
        {
            if(top == -1)
            {
                cout << "Stack Underflow! The stack is empty, cannot pop." << endl;
            }
            else
            {
                int data = memory[top--];
            
                cout << "Data popped from the stack: " << data << endl;
            }
        }
        
};

int main()
{
  Stack stack(4);
  
  stack.push(2);
  stack.push(1);
  stack.push(3);
  stack.push(7);
  
  //STACK OVERFLOW!
  stack.push(1);
  
  stack.pop();
  stack.push(4);
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  
  //STACK UNDERFLOW
  stack.pop();

  
  return 0;  
  
};