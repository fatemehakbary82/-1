#include<iostream>
using namespace std;

#define MAX 1000 //max size for stack

class Stack
{
   int top;
   public:
   int myStack[MAX]; //stack array

   Stack() { top = -1; }
   bool push(int x);
   int pop();
   bool isEmpty();
   bool isFull();
};
   //pushes element on to the stack
   bool Stack::push(int item)
   {
      if (top >= (MAX-1)) {
      cout << "Stack Overflow!!!";
      return false;
   }
else {
   myStack[++top] = item;
   cout<<item<<endl;
   return true;
   }
}

//removes or pops elements out of the stack
int Stack::pop()
{
   if (top < 0) {
      cout << "Stack Underflow!!";
      return 0;
   }
else {
       int item = myStack[top--];
      return item;
   }
}

//check if stack is empty
bool Stack::isEmpty()
{
   return (top < 0);
}

bool Stack::isFull()
{
   return (top == MAX- 1);
}

   int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty." <<endl;
            return -1;
        }
        return stack[top];
    }

    int size() {
        return top + 1;
    }
