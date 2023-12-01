#include <iostream>
using namespace std;

// تعریف ساختار گره (Node)
struct Node {
    int data;     // داده موجود در گره
    Node* next;   // پیوند به گره بعدی

    Node(int data) {
        this->data = data;   //data یک پارامتر برای اشاره به خود گره ای که نُد درون تابع سازنده درحال ایجاد است استفاده میشود
        this->next = nullptr;
    }
};

// تعریف کلاس لیست پیوندی
class LinkedList {
private:
    Node* head;   // اشاره‌گر به گره ابتدایی (سر لیست)

public:
    LinkedList() {
        head = nullptr;   //nulptr اشاره گری خالی را نشان میدهد و میتواند بجای هر نوع اشاره گر در برنامه استفاده شود
    }

    // تابع برای اضافه کردن عنصر به ابتدای لیست
    void prepend(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // تابع برای اضافه کردن عنصر به انتهای لیست
    void append(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;  //current متغیری است که نشان دهنده گره فعلی است که درحال پیمایش لیست است
        }

        current->next = newNode;
    }

    // تابع برای چاپ لیست پیوندی
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
