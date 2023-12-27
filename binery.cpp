#include <iostream>
using namespace std;

struct node 
{
  int data;
  struct node *left;
  struct node *right;
};

//تولید گره جدید
struct node *newNode(int data) 
{
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

// اضافه کردن یک عنصر جدید به درخت
struct node* insert(struct node* node, int value)
{
    // در صورتی که درخت خالی باشد، یک گره جدید ایجاد کنید و مقدار را به آن بدهید
    if (node == NULL)
        return newNode(value);

    // در صورتی که مقدار کوچکتر از مقدار گره فعلی باشد، به سمت گره چپ بروید
    if (value < node->data)
        node->left = insert(node->left, value);
    // در صورتی که مقدار بزرگتر یا مساوی مقدار گره فعلی باشد، به سمت گره راست بروید
    else if (value >= node->data)
        node->right = insert(node->right, value);

    return node;
}

// حذف یک عنصر از درخت
struct node* remove(struct node* root, int value)
{
    // در صورتی که درخت خالی باشد، هیچ تغییری انجام ندهید
    if (root == NULL)
        return root;

    // در صورتی که مقدار کوچکتر از مقدار گره فعلی باشد، به سمت گره چپ بروید
    if (value < root->data)
        root->left = remove(root->left, value);
    // در صورتی که مقدار بزرگتر یا مساوی مقدار گره فعلی باشد، به سمت گره راست بروید
    else if (value > root->data)
        root->right = remove(root->right, value);
    // در صورتی که مقدار برابر مقدار گره فعلی باشد
    else {
        // در صورتی که گره فعلی حاوی یک یا هیچ گره فرزندی نباشد، آن را حذف کنید
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // در صورتی که گره فعلی حاوی هر دو گره فرزند باشد
        // یافتن گره کوچکترین مقدار در زیردرخت راست
        struct node* temp = minValueNode(root->right);

        // جایگزین کردن مقدار گره جاری با گره کوچکترین مقدار
        root->data = temp->data;

        // حذف گره کوچکترین مقدار
        root->right = remove(root->right, temp->data);
    }
    return root;
}

// جستجوی یک عنصر در درخت
struct node* search(struct node* node, int value)
{
    // در صورتی که درخت خالی باشد یا مقدار مورد نظر را یافت کنید، برگردانید
    if (node == NULL || node->data == value)
        return node;

    // در صورتی که مقدار کوچکتر از مقدار گره فعلی باشد، به سمت گره چپ بروید
    if (value < node->data)
        return search(node->left, value);

    // در صورتی که مقدار بزرگتر از مقدار گره فعلی باشد، به سمت گره راست بروید
    return search(node->right, value);
}

// پیمایش پیش‌ترتیبی 
void traversePreOrder(struct node *temp) 
{
  if (temp != NULL) {
    cout  " " data;
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
  }
}

// پیمایش میان‌ترتیبی
void traverseInOrder(struct node *temp) 
{
  if (temp != NULL) {
    traverseInOrder(temp->left);
    cout  " " data;
    traverseInOrder(temp->right);
  }
}

// پیمایش پس‌ترتیبی
void traversePostOrder(struct node *temp) 
{
  if (temp != NULL) {
    traversePostOrder(temp->left);
    traversePostOrder(temp->right);
    cout  " " data;
  }
}
