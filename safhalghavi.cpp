#include<iostream>

const int MAX_SIZE = 100;

class CircularQueue {
private:
    int front;
    int rear;
    int queue[MAX_SIZE];

public:
    CircularQueue();
    bool isEmpty();
    bool isFull();
    void enqueue(int item);
    int dequeue();
    int peek();
    void reverse();
};

CircularQueue::CircularQueue() {
    front = -1;
    rear = -1;
}

bool CircularQueue::isEmpty() {
    return front == -1 && rear == -1;
}

bool CircularQueue::isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

void CircularQueue::enqueue(int item) {
    if (isFull()) {
        cout << "Error: Queue is full" << endl;
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }

    queue[rear] = item;
}

int CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Error: Queue is empty" << endl;
        return -1;
    }

    int item = queue[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    return item;
}

int CircularQueue::peek() {
    if (isEmpty()) {
        cout << "Error: Queue is empty" << endl;
        return -1;
    }

    return queue[front];
}

void CircularQueue::reverse() {
    if (isEmpty()) {
        return;
    }

    int i = front;
    int j = rear;

    while (i < j) {
        int temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;

        i = (i + 1) % MAX_SIZE;
        j = (j - 1 + MAX_SIZE) % MAX_SIZE;
    }
}



