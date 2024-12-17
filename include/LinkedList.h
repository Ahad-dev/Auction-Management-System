#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

// ListNode class template definition
template <class T>
class ListNode {
public:
    T data;
    ListNode* next;
    ListNode* prev;

    ListNode();  // Default constructor
    ListNode(const T& data);  // Parameterized constructor
};

// LinkedList class template definition
template <class T>
class LinkedList {
private:
    ListNode<T>* head;  // Pointer to the head ListNode
    ListNode<T>* tail;  // Pointer to the tail ListNode

public:
    LinkedList();  // Constructor
    ~LinkedList(); // Destructor

    // Functions to add, delete, and search ListNodes
    ListNode<T>* getHead() const;
    void addListNode(const T& data);
    void deleteListNode(const T& data);
    int countNode(ListNode<T>* node);
    int count();
    ListNode<T>* searchListNode(const T& data);
    bool hasCycle();  // Check for cycle in the linked list
    void testCycle(); // Test for cycle
};

// ListNode Constructor Definitions
template <class T>
ListNode<T>::ListNode() : data(T()), next(nullptr), prev(nullptr) {}

template <class T>
ListNode<T>::ListNode(const T& data) : data(data), next(nullptr), prev(nullptr) {}

// LinkedList Constructor Definition
template <class T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

// LinkedList Destructor Definition
template <class T>
LinkedList<T>::~LinkedList() {
    ListNode<T>* current = head;
    while (current != nullptr) {
        ListNode<T>* nextListNode = current->next;
        delete current;  // Free memory of the current ListNode
        current = nextListNode;
    }
    head = tail = nullptr;
}

// Add ListNode to the List
template <class T>
void LinkedList<T>::addListNode(const T& data) {
    ListNode<T>* newListNode = new ListNode<T>(data);

    if (head == nullptr) {
        // If the list is empty, both head and tail point to the new ListNode
        head = tail = newListNode;
    } else {
        // Otherwise, add the ListNode at the end and update tail
        tail->next = newListNode;
        newListNode->prev = tail;
        tail = newListNode;
    }
}

// Get Head of the List
template <class T>
ListNode<T>* LinkedList<T>::getHead() const {
    return head;
}

// Delete ListNode from the List
template <class T>
void LinkedList<T>::deleteListNode(const T& data) {
    ListNode<T>* current = head;

    // Traverse the list to find the ListNode to delete
    while (current != nullptr) {
        if (current->data == data) {
            // If the ListNode is found, handle the deletion
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
            delete current;  // Free memory of the ListNode
            return;
        }
        current = current->next;
    }

    cout << "ListNode not found!" << endl;  // If the ListNode is not found
}

// Search ListNode in the List
template <class T>
ListNode<T>* LinkedList<T>::searchListNode(const T& data) {
    ListNode<T>* current = head;

    // Traverse the list to find the ListNode
    while (current != nullptr) {
        if (current->data == data) {
            return current;  // Return the ListNode if found
        }
        current = current->next;
    }
    return nullptr;  // Return nullptr if the ListNode is not found
}

// Check for cycle in the linked list
template <class T>
bool LinkedList<T>::hasCycle() {
    ListNode<T>* slow = head;
    ListNode<T>* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // Move slow pointer by one
        fast = fast->next->next;    // Move fast pointer by two

        if (slow == fast) {
            return true;  // Cycle detected
        }
    }
    return false;  // No cycle
}

// Test for cycle
template <class T>
void LinkedList<T>::testCycle() {
    if (hasCycle()) {
        cout << "Cycle detected in the list!" << endl;
    } else {
        cout << "No cycle detected in the list." << endl;
    }
}

// Iterative countNode implementation
template <typename T>
int LinkedList<T>::countNode(ListNode<T>* node) {
    int count = 0;
    while (node != nullptr) {
        count++;
        node = node->next;
    }
    return count;
}

// Count the number of nodes in the list with safety check
template <typename T>
int LinkedList<T>::count() {
    if (hasCycle()) {
        cout << "Error: Linked list contains a cycle!" << endl;
        return -1;  // Indicate an error due to cycle
    }
    return countNode(head);
}

#endif // LINKEDLIST_H
