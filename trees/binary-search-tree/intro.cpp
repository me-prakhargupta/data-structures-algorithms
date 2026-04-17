/*
# What is Binary Search Tree?
- A BST is a special type of binary tree where nodes follow an order:
- For every node:
- All values in the left subtree are smaller
- All values in the right subtree are greater
- left < root < right

# Time Complexity
- Search => O(log N) if balanced
- Insert => O(log N)
- Delete => O(log N)

# Successor & Predecessor
- Inorder successor => next greater element
- Inorder predecessor => next smaller element
*/


#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Tree {
public:
    Node* insert(Node* root, int val) {
        if(root == nullptr) {
            return new Node(val);
        }

        if(val < root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }

        return root;
    }

    void inorder(Node* root) {
        if(!root) return;

        inorder(root->left);
        if(root->data != -1) {
            cout << root->data << " ";
        }
        inorder(root->right);
    }
};

int main() {
    vector<int> values = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};

    Tree t;
    Node* root = nullptr;
    
    for(int val : values) {
        root = t.insert(root, val);
    }

    t.inorder(root);
    return 0;
}