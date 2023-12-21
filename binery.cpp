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