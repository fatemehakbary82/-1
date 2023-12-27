#include <iostream>
#include <vector>
using namespace std;

class MinHeap 
{
 private:
    vector<int> heapArray;  //یک بردار از اعداد صحیح است و عملیات اصلی روی آن انجام میدهد

    void heapify(int index) //تابع کمکی 
    {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heapArray.size() && heapArray[leftChild] < heapArray[smallest])
            smallest = leftChild;

        if (rightChild < heapArray.size() && heapArray[rightChild] < heapArray[smallest])
            smallest = rightChild;

        if (smallest != index) 
        {
            swap(heapArray[index], heapArray[smallest]);
            heapify(smallest);
        }
    }

public:
    void insert(int value)  //عنصر جدید را درج میکند
    {
        heapArray.push_back(value);
        int currentIndex = heapArray.size() - 1;

        while (currentIndex != 0 && heapArray[currentIndex] < heapArray[(currentIndex - 1) / 2]) 
        {
            swap(heapArray[currentIndex], heapArray[(currentIndex - 1) / 2]);
            currentIndex = (currentIndex - 1) / 2;
        }
    }

    void remove()  //عنصر کمینه را حذف میکند 
    {
        if (heapArray.empty()) 
        {
            cout << "Heap is empty. Cannot remove element." << endl;
            return;
        }

        heapArray[0] = heapArray.back();
        heapArray.pop_back();

        heapify(0);
    }

    int getMin() //این تابع مقدار کمینه را از هیپ بازگردانده میکند
    {
        if (heapArray.empty()) 
        {
            cout << "Heap is empty." << endl;
            return INT_MAX;
        }
     
        return heapArray[0];
    }
};
