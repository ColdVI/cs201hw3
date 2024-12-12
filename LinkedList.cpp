#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP
#include "LinkedList.h"
#include "Node.h"
#include<iostream>

template <class T>
LinkedList<T>::LinkedList() : headptr(nullptr), itemCount(0) {}

template<class T>
LinkedList<T>::LinkedList(const T &aList): headptr(nullptr), itemCount(0) {
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = headptr;
    while (current != nullptr) {
        Node<T>* toDelete = current;
        current = current->getNext();

        delete toDelete;            // Delete the node
    }
    delete current;
    headptr = nullptr;
    itemCount = 0;
}

template <class T>

bool LinkedList<T>::insertSorted(const T& data) {
    // First check if item already exists
    if (exists(data)) {
        return false;
    }

    Node<T>* newNode = new Node<T>(data);

    // Case 1: Empty list or insert at beginning
    if (headptr == nullptr || headptr->getItem().getId() > data.getId()) {

        newNode->next = headptr;
        headptr = newNode;

        itemCount++;
        return true;
    }

    // Case 2: Insert in middle or end
    Node<T>* current = headptr;
    while (current->next != nullptr && current->next->getItem().getId() < data.getId()) {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
    itemCount++;
    return true;
}

template <class T>
bool LinkedList<T>::insert(const T& data) {
    if (exists(data)) {
        return false;  // Can't insert if it already exists
    }
    T newData = data;
    Node<T>* newNodePtr = new Node<T>(newData);
    if (itemCount == 0) {
        newNodePtr->next = headptr;
        headptr = newNodePtr;
        itemCount++;
        return true;
    }
    Node<T>* current = headptr;
    while (current->next !=nullptr) {


    }

    newNodePtr->next = current->next;
    current->setNext(newNodePtr);
    itemCount++;
    return true;
}


template <class T>
bool LinkedList<T>::remove(const T& data) {
    if (isEmpty()) {
        return false;
    }

    // Special case: removing head node
    if (headptr->getItem().getId() == data.getId()) {
        Node<T>* oldHead = headptr;
        headptr = headptr->next;
        delete oldHead;
        itemCount--;
        return true;
    }

    // For all other nodes
    Node<T>* current = headptr;
    Node<T>* previous = nullptr;

    // Find the node to remove
    while (current != nullptr && current->getItem().getId() != data.getId()) {
        previous = current;
        current = current->next;
    }

    // If we found the node to remove
    if (current != nullptr) {
        previous->next = current->next;
        delete current;
        itemCount--;
        return true;
    }

    return false;  // Item not found
}

template <class T>
Node<T>* LinkedList<T>::find(const T& data) const {
    Node<T>* current = headptr;
    while (current != nullptr) {
        if (current->getItem().getId() == data.getId()) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template <class T>
bool LinkedList<T>::exists(const T& data) const {
    Node<T>* current = headptr;
    while (current != nullptr) {
        if (current->getItem().getId() == data.getId()) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<class T>
void LinkedList<T>::clear() {
    while (!isEmpty()) {
        Node<T>* toDelete = headptr;
        headptr = headptr->getNext();
    itemCount--;
        delete toDelete;            // Delete the node
    }

}

template<class T>
int LinkedList<T>::getLength() const {
    return itemCount;
}
template <class T>
Node<T>* LinkedList<T>::getNodeAt(int position) const {

    if (position == 0) {
        return headptr;
    }
    Node<T>* curPtr = headptr;
    for (int i = 0; i < position; i++) {
        curPtr = curPtr->next;
    }

    return curPtr;
}
template<class T>
T LinkedList<T>::getEntry(int position) const {
    bool ableToGet = position >= 1 && position < itemCount;
    if (ableToGet) {
        Node<T>* nodeptr = getNodeAt(position);
        return nodeptr->getItem();
    }

}

template<class T>
T LinkedList<T>::replace(int position, const T &newEntry) {
}

template <class T>
void LinkedList<T>::print() const{
    Node<T>* current = headptr;

    while (current) {
        current->item.print();
        current = current->next;
    }
}

template <class T>
bool LinkedList<T>::isEmpty() const {
    return headptr == nullptr;
}
#endif