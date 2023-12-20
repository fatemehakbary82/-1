#include <iostream>

//ساختمان داده درخت یک ساختار سلسله مراتبی است که از گره هایی تشکیل شده که هرکدام میتوانند مقداری داشته باشند. . به یک یا چند گره فرزند ارجاع دهد.
class TreeNode 
{ //کلاس برای نمایش گره های درخت
//هر گره شامل دو بخش مقدار و ارجاع به گره های فرزند است
 public:
    int value;  //مقدار گره
    TreeNode* left;  //ارجاع به گره فرزند چپ
    TreeNode* right;  //ارجاع به گره فرزند راست

    TreeNode(int val)  //سازنده
     {
        value = val;
        left = nullptr;
        right = nullptr;
     }
};

class Tree
 {
public:
    TreeNode* root;  //گره ریشه

    Tree()  //سازنده
    {
        root = nullptr;
    }

    void insert(int val)  //اضافه کردن یک عنصر به درخت
     {
        if (root == nullptr) //درصورتی که درخت خالی باشد
        {
            root = new TreeNode(val);
            return;
        }

        insertRecursive(root, val);  //اضافه کردن با استفاده از تابع بازگشتی
    }

private:
    void insertRecursive(TreeNode* node, int val)   //تابع بازگشتی برای اضافه کردن عنصر به درخت
    {
        if (val < node->value) //عنصر جدید کوچکتر از مقدار گره فعلی است
        {
            if (node->left == nullptr) //اگر گره چپ خالی باشد
            {
                node->left = new TreeNode(val);
            }
             else 
            {
                insertRecursive(node->left, val);  //اضافه کردن به زیر درخت چپ
            }
        } 
        else 
        {  //عنصر جدید بزرگتر یا مساوی مقدار گره فعلی است
            if (node->right == nullptr) 
            {  //اگر گره راست خالی بود
                node->right = new TreeNode(val);
            } 
            else
            {
                insertRecursive(node->right, val);  // اضافه کردن به زیر درخت راست
            }
        }
    }
};