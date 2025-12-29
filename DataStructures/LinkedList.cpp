#include "LinkedList.hpp"
#include <iostream>

Node::Node(int val) : value(val), nextPointer(nullptr) {}


LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::insertNode(std::unique_ptr<Node> newNode) {
    if (head == nullptr) {
        head = std::move(newNode);
        return;
    }

    Node* currentNode = head.get();
    while (currentNode->nextPointer) {
        currentNode = currentNode->nextPointer.get();
    }
    currentNode->nextPointer = std::move(newNode);
}

void LinkedList::deleteNode(int value) {
    if (head && head->value == value) {
    head = std::move(head->nextPointer);
    std::cout << "Deleted head node" << "\n";
    return;
    }

    if (head->value == value) {
        head = std::move(head->nextPointer);
        return;
    }

}

void LinkedList::findNode(int value) {
    if (!head) {
    std::cout << "Node not found (empty list)\n";
    return;
    }

    if (head->value == value) {
        std::cout << "Value found at head node" << "\n";
        return;
    }
    Node* currentNode = head->nextPointer.get();

    while (currentNode) {
        if (currentNode-> value == value) {
            std::cout << "Node found in linked list" <<  "\n";
            return;
        }
        currentNode = currentNode->nextPointer.get();
    }
    std::cout << "Node not found in linked list" << "\n";
    return;
}

void LinkedList::makeCircular() {
    if (!head) return;

    Node* currentNode = head.get();

    while (currentNode) {
        currentNode = currentNode->nextPointer.get();
    }
    currentNode->nextPointer.reset(head.get());

}

