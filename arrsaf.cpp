#include<iostream>
#include<math.h>
using namespace std;

const int Max_Size = 100;    //حداکثر تعداد عناصر در صف
struct Queue
{
    int elements[Max_Size];  //آرایه اعداد صحیح برای ذخیره عناصر صف
    int front;  //نشانگر ابتدای صف
    int rear;  //نشانگر انتهای صف
};

bool isEmpty(Queue& queue)   //تابع برسی صف خالی بودن
{
    return (queue.front == -1);
}

bool isFull(Queue& queue)   //تابع برسی صف پر بودن
{
    return(queue.rear == Max_Size - 1);
}

void Enqueue(Queue& queue , int element)  //تابع اضافه کردن به صف
{
    if(isFull(queue))
    {
        cout<< " صف پر است!"<<endl;
    }
    else
    {
        if(isEmpty(queue))
        {
            queue.front=0;
        }
        queue.rear++;
        queue.elements[queue.rear]=element;
        cout<< "عنصر"<<element<<"به صف اضافه شد."<<endl;
    }
}

void Dequeue(Queue& queue)  //تابع حذف از ابتدای صف
{
    if(isEmpty(queue))
    {
        cout<< "صف خالی است!"<<endl;
    }
    else
    {
        int removedElement=queue.elements[queue.front];
        if(queue.front==queue.rear)
        {
            queue.front=-1;
            queue.rear=-1;
        }
        else
        {
            queue.front++;
        }
        cout<<"عنصر"<<removedElement<<"از ابتدای صف حذف شد."<<endl;
    }
}

void reverseQueue(Queue& queue)  //تابع برعکس کردن صف
{
    if(isEmpty(queue))
    {
        cout<<"صف خالی است!"<<endl;
    }
    else
    {
        int i = queue.front;
        int j = queue.rear;
        while (i<j)
        {
           //جابه جایی عنصر
           int temp = queue.elements[i];
           queue.elements[i] = queue.elements[j];
           queue.elements[j] = temp;
           i++;
           j--;
        }
        cout<<"صف برعکس شد."<<endl;
    }
}

void peek(Queue& queue)   //تابع مشاهده گر از ابتدای صف بدون حذف
{
    if(isEmpty(queue))
    {
        cout<<"صف خالی است!"<<endl;
    }
    else
    {
        cout<<"عنصر ابتدای صف:"<<queue.elements[queue.front]<<endl;
    }
}
