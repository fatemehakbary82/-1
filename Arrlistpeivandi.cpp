#include <iostream>
#include <math.h>
using namespace std;

class Node  //برای نمایش یک گره در لیست پیوندی استفاده خواهد شد
{
 public:
    int data;  //نگهدارنده داده موجود در گره 
    Node* next;  //اشاره گر به گره بعدی در لیست پیوندی
};

class LinkedList  //برای پیاده سازی لیست پیوندی بعنوان ساختمان داده آرایه استفاده میشود
{
 private:
    Node* head;  //اشاره گر به گره اول لیست پیوندی 
 public:
    LinkedList()   //سازنده برای ساختن لیست پیوندی خالی
    {
        head = nullptr;
    }

    void insert(int k, int x)  //برای اضافه کردن
    {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;

        if (k == 0) 
        {
            newNode->next = head;
            head = newNode;
        }
         else 
         {
            Node* temp = head;
            for (int i = 0; i < k - 1; i++)
             {
                temp = temp->next;
             }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    int remove(int k)  //حذف کردن
     {
        if (k == 0)
        {
            int x = head->data;
            Node* temp = head;
            head = head->next;
            delete temp;
            return x;
        } 
        else
        {
            Node* temp = head;
            for (int i = 0; i < k - 1; i++)
            {
                temp = temp->next;
            }
            Node* deleteNode = temp->next;
            int x = deleteNode->data;
            temp->next = deleteNode->next;
            delete deleteNode;
            return x;
        }
    }

    int find(int x)  // جستوجو در لیست پیوندی
    {
        Node* temp = head;
        int index = 0;
        while (temp != nullptr) 
        {
            if (temp->data == x) 
            {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }
};
