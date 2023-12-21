#include <iostream>
using namespace std;

class HashTable 
{
private:
    static const int tableSize = 10;
    <list> table[tableSize];

public:
    int hashFunction(int key)  //برای تعین اندیس در جدول هاش براساس کلید استفاده میشود
    {
        return key % tableSize;
    }

    void insert(int key, string value)  //برای اضافه کردن یک جفت کلید و مقدار به جدول هاش استفاده میشود
    {
        int index = hashFunction(key);
        table[index].push_back(make_pair(key, value));
    }

    void remove(int key)  //برای حذف کردن یک عنصر از جدول هاش براساس کلید استفاده میشود
    {
        int index = hashFunction(key);  //ابتدا با این تابع اندیس محاسبه میشود سپس عنصر مربوطه از لیست در ایندکس حذف میشود
        for (auto it = table[index].begin(); it != table[index].end(); it++) 
        {
            if (it-&gt;first == key) 
            {
                table[index].erase(it);
                break;
            }
        }
    }

    void search(int key)  // برای جستوجو یک عنصر در جدول هاش براساس کلید استفاده میشود
    {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++) 
        {
            if (it->first == key) 
            {
                cout<<"Key:"<<it->first <<"Value:"<<it->second <<endl;
                return;
            }
        }
        cout<<"Key not found"<<endl;
    }
};

