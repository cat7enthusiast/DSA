#include "LinkedList.hpp"
#include <iostream>

Node::Node(int val) : value(val), nextPointer(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::insertNode(std::shared_ptr<Node> newNode) {
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    std::shared_ptr<Node> currentNode = head;
    while (currentNode->nextPointer) {
        currentNode = currentNode->nextPointer;
    }
    currentNode->nextPointer = newNode;
}

void LinkedList::deleteNode(int value) {
    if (!head) {
        std::cout << "List is empty\n";
        return;
    }
    
    if (head->value == value) {
        head = head->nextPointer;
        std::cout << "Deleted head node\n";
        return;
    }
    
    std::shared_ptr<Node> currentNode = head;
    while (currentNode->nextPointer) {
        if (currentNode->nextPointer->value == value) {
            currentNode->nextPointer = currentNode->nextPointer->nextPointer;
            std::cout << "Deleted node with value " << value << "\n";
            return;
        }
        currentNode = currentNode->nextPointer;
    }
    
    std::cout << "Node with value " << value << " not found\n";
}

void LinkedList::findNode(int value) {
    if (!head) {
        std::cout << "Node not found (empty list)\n";
        return;
    }
    
    if (head->value == value) {
        std::cout << "Value found at head node\n";
        return;
    }
    
    std::shared_ptr<Node> currentNode = head->nextPointer;
    while (currentNode) {
        if (currentNode->value == value) {
            std::cout << "Node found in linked list\n";
            return;
        }
        currentNode = currentNode->nextPointer;
    }
    
    std::cout << "Node not found in linked list\n";
}

void LinkedList::makeCircular() {
    if (!head) return;
    
    std::shared_ptr<Node> currentNode = head;
    while (currentNode->nextPointer) {
        currentNode = currentNode->nextPointer;
    }
    
    currentNode->nextPointer = head;
}