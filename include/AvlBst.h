#ifndef AVL_BST_CPP
#define AVL_BST_CPP
#include <iostream>
using namespace std;

// AVL Tree Node structure (template version)
template <typename T>
struct Node {
    int key;
    T data;
    Node* left;
    Node* right;
    int height;

    // Constructor to initialize a node
    Node(int key ,T data) : key(key), left(nullptr), right(nullptr), height(1), data(data) {}
};

// AVL Tree class template
template <typename T>
class AVLTree {
private:
    Node<T>* root;

    // Get height of a node
    int height(Node<T>* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    // Get balance factor of node
    int getBalance(Node<T>* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    // Right rotate subtree rooted with y
    Node<T>* rightRotate(Node<T>* y) {
        Node<T>* x = y->left;
        Node<T>* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Left rotate subtree rooted with x
    Node<T>* leftRotate(Node<T>* x) {
        Node<T>* y = x->right;
        Node<T>* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // Insert a node and balance the tree
    Node<T>* insert(Node<T>* node, int key, T data) {
        if (node == nullptr) {
            return new Node<T>(key, data);
        }

        if (key < node->key) {
            node->left = insert(node->left, key, data);
        } else if (key > node->key) {
            node->right = insert(node->right, key, data);
        } else {
            return node;  // Duplicate keys are not allowed
        }

        node->height = max(height(node->left), height(node->right)) + 1;

        // Get balance factor
        int balance = getBalance(node);

        // Left heavy tree
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }

        // Right heavy tree
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }

        // Left-right case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right-left case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // In-order traversal of the AVL tree
    void inOrder(Node<T>* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }

    // Count nodes
    int countNodes(Node<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

public:
    // Constructor to initialize the tree
    AVLTree() : root(nullptr) {}

    // Insert a key and data into the AVL tree
    void insert(int key, T data) {
        root = insert(root, key, data);
    }

    // Perform in-order traversal
    void inOrderTraversal() {
        inOrder(root);
        cout << endl;
    }

    // Get root
    Node<T>* getRoot() {
        return root;
    }

    // Count nodes
    int countNodes() {
        return countNodes(root);
    }
};

#endif
