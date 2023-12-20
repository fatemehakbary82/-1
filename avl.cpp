#include <iostream>
using namespace std;

// ساختار گره درخت AVL
struct Node
{
    int data; // داده
    Node* left; // اشاره‌گر به گره چپ
    Node* right; // اشاره‌گر به گره راست
    int height; // ارتفاع گره
};

// تابع برای محاسبه حداکثر دو عدد
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

// تابع برای محاسبه ارتفاع گره
int getHeight(Node* node) 
{
    if (node == nullptr)
        return 0;
    return node->height;
}

// تابع برای ایجاد گره جدید با داده مشخص شده بصورتی که اشاره گر ها به نال پیتیآر و ارتفاع گره برابر 1 باشد
Node* createNode(int data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

// تابع برای انجام عملیات چرخش به راست
Node* rotateRight(Node* z) 
{
    Node* y = z->left;
    Node* T3 = y->right;

    y->right = z;
    z->left = T3;

    z->height = 1 + max(getHeight(z->left), getHeight(z->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

// تابع برای انجام عملیات چرخش به چپ
Node* rotateLeft(Node* z) 
{
    Node* y = z->right;
    Node* T2 = y->left;

    y->left = z;
    z->right = T2;

    z->height = 1 + max(getHeight(z->left), getHeight(z->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

// تابع برای افزودن گره به درخت AVL
Node* insertNode(Node* root, int data) 
{
    // مرحله 1: افزودن گره به صورت معمول در BST
    if (root == nullptr)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    else // گره تکراری را نادیده می‌گیریم
        return root;

    // مرحله 2: به‌روزرسانی ارتفاع گره
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // مرحله 3: بررسی و تصحیح تعادل درخت
    int balanceFactor = getHeight(root->left) - getHeight(root->right);

    // اگر درخت به سمت چپ شیب دارد
    if (balanceFactor > 1) 
    {
        // حالت 1: درج در زیردرخت چپ چپ
        if (data < root->left->data)
            return rotateRight(root);

        // حالت 2: درج در زیردرخت چپ راست
        if (data > root->left->data) 
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    // اگر درخت به سمت راست شیب دارد
    if (balanceFactor < -1) 
    {
        // حالت 3: درج در زیردرخت راست راست
        if (data > root->right->data)
            return rotateLeft(root);

        // حالت 4: درج در زیردرخت راست چپ
        if (data < root->right->data) 
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

// تابع برای نمایش درخت به صورت Inorder
void inorderTraversal(Node* root) 
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
