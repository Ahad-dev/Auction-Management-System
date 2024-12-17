#ifndef AVL_BST_CPP
#define AVL_BST_CPP
#include <iostream>
using namespace std;

// AVL Tree Node structure (template version)
template <typename T>
struct Node {
    int key;
    string name;
    T data;
    Node* left;
    Node* right;
    int height;

    Node(int key, T data, string name = "") : key(key), left(nullptr), right(nullptr), height(1), data(data), name(name) {}
};

// AVL Tree class template
template <typename T>
class AVLTree {
private:
    Node<T>* root;

    int height(Node<T>* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int getBalance(Node<T>* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    Node<T>* rightRotate(Node<T>* y) {
        Node<T>* x = y->left;
        Node<T>* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node<T>* leftRotate(Node<T>* x) {
        Node<T>* y = x->right;
        Node<T>* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node<T>* insert(Node<T>* node, int key, T data, string name = "") {
        if (node == nullptr) {
            return new Node<T>(key, data, name);
        }

        if (key < node->key) {
            node->left = insert(node->left, key, data, name);
        } else if (key > node->key) {
            node->right = insert(node->right, key, data, name);
        } else {
            return node;
        }

        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key) return rightRotate(node);
        if (balance < -1 && key > node->right->key) return leftRotate(node);
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inOrder(Node<T>* root) {
        if (root) {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }

    int countNodes(Node<T>* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    Node<T>* searchByKey(Node<T>* root, int key) {
        while (root) {
            if (key == root->key) return root;
            root = (key < root->key) ? root->left : root->right;
        }
        return nullptr;
    }

    Node<T>* searchByUsername(Node<T>* root, string name) {
        if (!root) return nullptr;
        if (root->name == name) return root;

        Node<T>* leftResult = searchByUsername(root->left, name);
        if (leftResult) return leftResult;

        return searchByUsername(root->right, name);
    }

    Node<T>* getMinValueNode(Node<T>* root) {
        while (root && root->left) root = root->left;
        return root;
    }

    Node<T>* Delete(Node<T>* root, int key) {
        if (!root) return root;

        if (key < root->key) root->left = Delete(root->left, key);
        else if (key > root->key) root->right = Delete(root->right, key);
        else {
            if (!root->left || !root->right) {
                Node<T>* temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            } else {
                Node<T>* temp = getMinValueNode(root->right);
                root->key = temp->key;
                root->right = Delete(root->right, temp->key);
            }
        }

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key, T data, string name = "") {
        root = insert(root, key, data, name);
    }

    void inOrderTraversal() {
        inOrder(root);
        cout << endl;
    }

    int countNodes() {
        return countNodes(root);
    }

    Node<T>* SearchNode(int key) {
        return searchByKey(root, key);
    }

    Node<T>* searchByUsername(string name) {
        return searchByUsername(root, name);
    }

    void Delete(int key) {
        root = Delete(root, key);
    }
    Node<T>* getRoot(){
        return root;
    }
};

#endif
