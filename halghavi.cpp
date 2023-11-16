#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int front, rear, size;
    int arr[MAX_SIZE];
public:
    Queue() {
        front = rear = -1;
        size = 0;
    }
    bool isFull() {
        return (rear+1)%MAX_SIZE == front;
    }
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    void enqueue(int x) {
        if(isFull()) {
            cout <<"Error: Queue is full&quot"<<  endl;
            return;
        }
        else if(isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear+1)%MAX_SIZE;
        }
        arr[rear] = x;
        size++;
    }
    void dequeue() {
        if(isEmpty()) {
            cout<<"Error: Queue is empty&quot"<< endl;
            return;
        }
        else if(front == rear) {
            front = rear = -1;
        }
        else {
            front = (front+1)%MAX_SIZE;
        }
        size--;
    }
    int peek() {
        if(isEmpty()) {
            cout<<"Error: Queue is empty&quot"<< endl;
            return -1;
        }
        return arr[front];
    }
    void reverse() {
        if(isEmpty()) {
            cout <<"Error: Queue is empty&quot"<< endl;
            return;
        }
        int temp[MAX_SIZE];
        int i = 0;
        while(!isEmpty()) {
            temp[i] = peek();
            dequeue();
            i++;
        }
        for(int j = i-1; j &gt;= 0; j--) {
            enqueue(temp[j]);
        }
    }
    int getSize() {
        return size;
    }
};

