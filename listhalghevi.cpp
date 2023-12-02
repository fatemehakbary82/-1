#include <iostream>
using namespace std;

// تعریف ساختار گره
struct Node
{
    int data;   //ذخیره مقدار عنصر
    Node* next;  //نشان دادن به گره بعدی لیست 
};

// تعریف کلاس لیست پیوندی حلقوی
class CircularLinkedList 
{
private:
    Node* head;  //به گره ابتدایی لیست اشاره دارد

public:
    CircularLinkedList()
    {
        head = nullptr;  //که نشان دهد لیست خالی است
    }

    // تابع برای اضافه کردن یک عنصر به لیست
    void addElement(int value) 
    {
        Node* newNode = new Node;  //گره جدید
        newNode->data = value;  

        if (head == nullptr)
        {
            // اگر لیست خالی است
            head = newNode;   //head را به گره جدید نسبت میدهیم
            newNode->next = head;  //next گره جدید را بخودش تنظیم میکند 
        }
         else
        {
            // اگر لیست حاوی عناصر است
            Node* current = head;  //به عقب برویم تا به آخرین گره برسیم و گره جدید را به آن متصل کنیم
            while (current->next != head)  //تازمانی که برابر نباشد به عقب حرکت میکنیم
            {
                current = current->next;  //در هر مرحله current را به گره بعدی منتقل میکنیم
            }
            current->next = newNode;
            newNode->next = head;  //گره فعلی به گره جدید نسبت دهیم تا لیست حلقوی شود 
        }
        cout << "عنصر " << value << " به لیست اضافه شد." << endl;
    }

    // تابع برای نمایش عناصر لیست
    void displayList() {
        if (head == nullptr) {
            cout << "لیست خالی است." << endl;
            return;
        }

        Node* current = head;  //بصورت حلقوی از ابتدا تا انتها عصانصر نمایش شود
        cout << "عناصر لیست: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};