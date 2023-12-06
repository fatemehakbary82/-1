#include <iostream>

// تعریف ساختار گره
struct Node {
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
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

}
