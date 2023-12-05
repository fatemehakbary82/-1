#include<iostream>
#include<stack>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node* top;  //اين اشاره گر به بالاترين عنصر پشته است

public:
    Stack()
    {
        top = nullptr;  //اشاره گر خالي تنظيم ميشود
    }

    bool isEmpty()
    {
        return (top == nullptr);
    }

    void push(int item)  //عنصر جديد به بالاي پشته اضافه ميكند
    {
        Node* newNode = new Node(item); 
        newNode->next = top;
        top = newNode;
        cout << item << " pushed to stack." << endl;
    }

    int pop()   //عنصر بالاي پشته را حذف و بعنوان مقدار بازگشتي برميگرداند
    {
        if (isEmpty()) 
        {
            cout << "Stack Underflow!!" << endl;
            return 0;
        }
        Node* temp = top;
        int item = temp->data;
        top = top->next;
        delete temp;
        return item;
    }

    int peek()   //مقدار عنصر بالاي پشته را بدون حذف كردن آن برميگرداند
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }
};
