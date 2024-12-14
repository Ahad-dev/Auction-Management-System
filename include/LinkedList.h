#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

// make the Node class a template
template <class T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node();
    Node(const T& data);
};

// make the LinkedList class a template
template <class T>
class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
    LinkedList();
    ~LinkedList();

    // make the functions add node delete node search node
    Node<T>* getHead() const;
    void addNode(const T& data);
    void deleteNode(const T& data);
    Node<T>* searchNode(const T& data);
};




#endif