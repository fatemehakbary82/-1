#include <iostream>
using namespace std;

class Node //يك گره در ليست پيوندي را نشان ميدهد
{
public:
    int data;  //عدد موجود در گره را نشان ميدهد
    Node* next;  //يك اشاره گر به گره بعدي در ليست پيوندي است

    Node(int data) 
    {
        this->data = data;  //مقدار ديتا دريافتي به متغير ديتا درون اشاره گر ديس اختصاص داد ميشود
        next = nullptr;
    }  //به اين ترتيب سازنده نود به شكل درستي مقدار ديتا را در گره مورد نظر قرار ميدهد.
};

class Queue 
{
private:
    Node* front; // اشاره‌گر به ابتدای صف
    Node* rear; // اشاره‌گر به انتهای صف
    int size; // تعداد اعضای موجود در صف

public:
    Queue() //عمليات مقداردهي اوليه براي متغير هاي عضو كلاس را دارد
    {
        front = nullptr; //تنظيم صف خالي
        rear = nullptr; // تنظيم صف خالي
        size = 0;
    }  //صف خالي با حجم صفر ايجاد شد

    // متد بررسی صف خالی بودن
    bool isEmpty() {
        return size == 0;
    }

    // متد اضافه کردن به صف
    void enqueue(int item) {
        Node* newNode = new Node(item);

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
        cout << "عنصر " << item << " به صف اضافه شد." << endl;
    }

    // متد حذف از ابتدای صف
    void dequeue() {
        if (isEmpty()) {
            cout << "صف خالی است." << endl;
            return;
        }

        int item = front->data;
        Node* temp = front;

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;

        size--;
        cout << "عنصر " << item << " از صف حذف شد." << endl;
    }

    // متد مشاهده عنصر ابتدای صف بدون حذف
    int peek() {
        if (isEmpty()) {
            cout << "صف خالی است." << endl;
            return -1; // یک مقدار دلخواه برای نشان‌دادن خطا
        }

        return front->data;
    }

    // متد برعکس کردن صف
    void reverse() {
        if (isEmpty()) {
            cout << "صف خالی است." << endl;
            return;
        }

        Node* current = front;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        rear = front;
        front = prev;

        cout << "صف برعکس شد." << endl;
    }
};