#pragma once

#include <memory>

struct Node {
    int value;
    std::unique_ptr<Node> nextPointer;

    Node(int val);
};

class LinkedList {
    private:
        std::unique_ptr<Node> head;
    
    public:
        LinkedList();
        void insertNode(std::unique_ptr<Node> newNode);
        void deleteNode(int value);
        void findNode(int value);
};