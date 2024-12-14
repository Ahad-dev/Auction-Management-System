#include "../../include/LinkedList.h"

// Node Constructor Definitions
template <class T>
Node<T>::Node() : data(T()), next(nullptr), prev(nullptr) {}

template <class T>
Node<T>::Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}


// LinkedList Constructor Definition
template <class T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

// LinkedList Destructor Definition
template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
}

// Add Node to the List
template <class T>
void LinkedList<T>::addNode(const T& data) {
    Node<T>* newNode = new Node<T>(data);

    if (head == nullptr) {
        // If the list is empty, both head and tail point to the new node
        head = tail = newNode;
    } else {
        // Otherwise, add the node at the end and update tail
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

//get Head
template <class T>
Node<T>* LinkedList<T>::getHead() const{
    return head;
}

// Delete Node from the List
template <class T>
void LinkedList<T>::deleteNode(const T& data) {
    Node<T>* current = head;

    // Traverse the list to find the node to delete
    while (current != nullptr) {
        if (current->data == data) {
            // If the node is found, handle the deletion
            if (current == head) {
                head = current->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            } else if (current == tail) {
                tail = current->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }

    cout << "Node not found!" << endl;
}

// Search Node in the List
template <class T>
Node<T>* LinkedList<T>::searchNode(const T& data) {
    Node<T>* current = head;

    // Traverse the list to find the node
    while (current != nullptr) {
        if (current->data == data) {
            return current;  // Return the node if found
        }
        current = current->next;
    }
    return nullptr;  // Return nullptr if node is not found
}
