#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    Node* insertRecursive(Node* node, int key) 
    {
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insertRecursive(node->left, key);
        else if (key > node->key)
            node->right = insertRecursive(node->right, key);

        return node;
    }

    Node* findMin(Node* node) 
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* removeRecursive(Node* node, int key) 
    {
        if (node == nullptr)
            return node;

        if (key < node->key)
            node->left = removeRecursive(node->left, key);
        else if (key > node->key)
            node->right = removeRecursive(node->right, key);
        else {
            if (node->left == nullptr) 
            {
                Node* temp = node->right;
                delete node;
                return temp;
            } 
            else if (node->right == nullptr) 
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->right = removeRecursive(node->right, temp->key);
        }

        return node;
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    void remove(int key) {
        root = removeRecursive(root, key);
    }
};

