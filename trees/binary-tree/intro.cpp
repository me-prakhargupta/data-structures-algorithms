/*
# What is a Tree?
- A Tree is a hierarchical data structure where:
- There is a root node
- Each node can have childer
- No cycle (unlike Graphs)

Think of it like a family tree.

# Core Terminology

- Node: Basic unit of tree, contains data + pointer (links)
- Root: Topmost node, starting point of tree
- Leaf: Node with no children
- Internal Node: Node with atleast one child
- Degree: Number of childer
*/

#include<iostream>
#include<stack>
#include<queue>
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
    Node* buildTree(vector<int>& nodes, int& idx) {
        if(nodes[idx] == -1 || idx >= nodes.size()) {
            idx++;
            return nullptr;
        }

        Node* root = new Node(nodes[idx++]);
        root->left = buildTree(nodes, idx);
        root->right = buildTree(nodes, idx);

        return root;
    }

    // Recursive - Preorder
    void preorder(Node* root) {
        if(root == nullptr) {
            return;
        }

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // Iterative - Preorder
    void preorderIterative(Node* root) {
        if(root == nullptr) return;

        stack<Node*> st;
        st.push(root);

        while(!st.empty()) {
            Node* top = st.top();
            st.pop();

            cout << top->data << " ";
            if(top->right) st.push(top->right);
            if(top->left) st.push(top->left);
        }
    }

    // Recursive - Inorder
    void inorder(Node* root) {
        if(root == nullptr) {
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Iterative - Inorder
    void inorderIterative(Node* root) {
        stack<Node*> st;
        Node* curr = root;

        while(curr != nullptr || !st.empty()) {
            while(curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            cout << curr->data << " ";

            curr = curr->right;
        }
    }

    // Recursive - Postorder
    void postorder(Node* root) {
        if(root == nullptr) {
            return;
        }

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    // Iterative - Postorder
    void postorderIterative(Node* root) {
        stack<Node*> st;
        Node* curr = root;
        Node* lastVisited = nullptr;

        while(curr != nullptr || !st.empty()) {
            while(curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            Node* top = st.top();
            if(top->right && lastVisited != top->right) {
                curr = top->right;
            } else {
                cout << top->data << " ";
                lastVisited = top;
                st.pop();
            }
        }
    }

    // Iterative - Levelorder
    void levelorder(Node* root) {
        if(root == nullptr) {
            return;
        }
    
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* front = q.front();
            q.pop();

            cout << front->data << " ";
            if(front->left != nullptr) {
                q.push(front->left);
            }
            if(front->right != nullptr) {
                q.push(front->right);
            }
        }
    }

    // Iterative - Level wise
    void levelWiseTraversal(Node* root) {
        if(root == nullptr) return;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                Node* front = q.front();
                q.pop();

                cout << front->data << " ";
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            cout << endl;
        }
    }
};

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};

    Tree t;
    int idx = 0;
    
    Node* root = t.buildTree(nodes, idx);

    cout << "[PREORDER] Recursive: "; t.preorder(root);
    cout << endl;
    cout << "[PREORDER] Iterative: "; t.preorderIterative(root);

    cout << endl << endl;
    cout<< "[INORDER] Recursive: "; t.inorder(root);
    cout << endl;
    cout << "[INORDER] Iterative: "; t.inorderIterative(root);

    cout << endl << endl;
    cout << "[POSTORDER] Recursive: "; t.postorder(root);
    cout << endl;
    cout << "[POSTORDER] Iterative: "; t.postorderIterative(root);

    cout << endl << endl;
    cout << "[LEVELORDER] Iterative: "; t.levelorder(root);
    cout << endl;
    cout << "[LEVELORDER]: Level Wise: " << endl; t.levelWiseTraversal(root);
    return 0;
}