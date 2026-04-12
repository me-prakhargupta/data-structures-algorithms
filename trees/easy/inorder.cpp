#include<iostream>
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
    Node* root;

    void inorder(Node* root) {
        if(root == nullptr) return;

        inorder(Node* root->left);
        cout << root->data << " -> ";
        inorder(Node* root->right);
    }
};


int main() {
    return 0;
}