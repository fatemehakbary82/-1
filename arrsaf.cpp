#include <iostream>
using namespace std;

class Queue {
private:
    int* arr; // آرایه برای نگهداری اعضای صف
    int capacity; // ظرفیت صف
    int front; // اشاره‌گر به ابتدای صف
    int rear; // اشاره‌گر به انتهای صف
    int size; // تعداد اعضای صف

public:
    // سازنده
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // متد بررسی صف خالی بودن
    bool isEmpty() {
        return size == 0;
    }

    // متد بررسی صف پر بودن
    bool isFull() {
        return size == capacity;
    }

    // متد اضافه کردن به صف
    void enqueue(int item) {
        if (isFull()) {
            cout << "صف پر است." <<endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
        cout << "عنصر " << item << " به صف اضافه شد." << endl;
    }

    // متد حذف از ابتدای صف
    void dequeue() {
        if (isEmpty()) {
            cout << "صف خالی است." << endl;
            return;
        }

        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        cout << "عنصر " << item << " از صف حذف شد." << endl;
    }

    // متد مشاهده عنصر ابتدای صف بدون حذف
    int peek() {
        if (isEmpty()) {
            cout << "صف خالی است." << endl;
            return -1; // یک مقدار دلخواه برای نشان‌دادن خطا
        }

        return arr[front];
    }

    // متد برعکس کردن صف
    void reverse() {
        if (isEmpty()) {
            cout << "صف خالی است." <<endl;
            return;
        }

        int* reversedArr = new int[capacity];
        int index = 0;

        for (int i = size - 1; i >= 0; i--) {
            reversedArr[index++] = arr[i];
        }

        delete[] arr;
        arr = reversedArr;

        front = 0;
        rear = size - 1;

        cout << "صف برعکس شد." <<endl;
    }
};
