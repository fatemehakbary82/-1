#include <iostream>
using namespace std;

// تعریف ساختار گره
struct Node
 {
    int data;
    Node* prev; // پیوند به گره قبلی
    Node* next; // پیوند به گره بعدی
};

// کلاس لیست پیوندی دوطرفه
class DoublyLinkedList 
{
private:
    Node* head; // اشاره‌گر به گره ابتدایی
    Node* tail; // اشاره‌گر به گره انتهایی
    int size;   // سایز لیست

public:
    // سازنده
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
 // متد برای درج گره در مکان مشخص
    void InsertAtIndex(int data, int index)
    {
        if (index < 0 || index > size)
            return; // ایندکس غیرمجاز است

        Node* newNode = new Node;
        newNode->data = data;

        if (index == 0) 
        {
            // درج در ابتدا
            newNode->prev = nullptr;
            newNode->next = head;

            if (head != nullptr)
                head->prev = newNode;

            head = newNode;

            if (tail == nullptr)
                tail = newNode;
         } 
        else if (index == size)
        {
            // درج در انتها
            newNode->prev = tail;
            newNode->next = nullptr;

            if (tail != nullptr)
                tail->next = newNode;

            tail = newNode;

            if (head == nullptr)
                head = newNode;
        } else {
            // درج در مکان میانی
            Node* current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }

            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
        }

        size++;
    }

    // متد برای درج گره در ابتدا
    void InsertAtBegin(int data) 
    {
        InsertAtIndex(data, 0);
    }

    // متد برای درج گره در انتها
    void InsertAtEnd(int data)
     {
        InsertAtIndex(data, size);
    }

    // متد برای به‌روزرسانی مقدار گره در اندیس مشخص
    void UpdateNode(int data, int index)
     {
        if (index < 0 || index >= size)
            return; // ایندکس غیرمجاز است

        Node* current = head;
        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }

        current->data = data;
    }

    // متد برای حذف گره در اندیس مشخص و بازگرداندن مقدار آن
    int RemoveNodeAtIndex(int index) 
    {
        if (index < 0 || index >= size)
            return -1; // ایندکس غیرمجاز است

        int removedData;
        Node* removedNode;

        if (index == 0) 
        {
            // حذف از ابتدا
            removedNode = head;
            removedData = removedNode->data;

            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;

            if (removedNode == tail)
                tail = nullptr;
        } 
        else if (index == size - 1)
         {
            // حذف از انتها
            removedNode = tail;
            removedData = removedNode->data;

            tail = tail->prev;
            if (tail != nullptr)
                tail->next = nullptr;

            if (removedNode == head)
                head = nullptr;
        }
         else 
         {
            // حذف از مکان میانی
            Node* current = head;
            forint i = 0; i < index; i++) 
            {
                current = current->next;
            }

            removedNode = current->next;
            removedData = removedNode->data;

            current->next = removedNode->next;
            removedNode->next->prev = current;
        }

        delete removedNode;
        size--;

        return removedData;
    }

    // متد برای حذف گره از انتها و بازگرداندن مقدار آن
    int RemoveNodeAtEnd()
    {
        return RemoveNodeAtIndex(size - 1);
    }

    // متد برای حذف گره از ابتدا و بازگرداندن مقدار آن
    int RemoveNodeAtBegin() 
    {
        return RemoveNodeAtIndex(0);
    }

    // متد برای بازگرداندن سایز لیست
    int SizeofList() 
    {
        return size;
    }

    // متد برای اتصال دو لیست پیوندی
    void Concatenate(DoublyLinkedList& list) 
    {
        if (list.head == nullptr)
            return; // لیست دوم خالی است

    if (head == nullptr) 
    {
            // لیست اصلی خالی است
            head = list.head;
            tail = list.tail;
        } 
        else 
        {
            // لیست اصلی و لیست دوم غیرخالی هستند
            tail->next = list.head;
            list.head->prev = tail;
            tail = list.tail;
        }

        size += list.size;

        // پاک کردن لیست دوم
        list.head = nullptr;
        list.tail = nullptr;
        list.size = 0;
    }

    // متد برای برعکس کردن لیست
    void Invert() 
    {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) 
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev;
        }

        // تغییر سر و ته لیست
        temp = head;
        head = tail;
        tail = temp;
    }
};

