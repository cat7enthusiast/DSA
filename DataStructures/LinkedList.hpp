#pragma once

#include <memory>

struct Node {
    int value;
    std::shared_ptr<Node> nextPointer;

    Node(int val);
};

class LinkedList {
    private:
        std::shared_ptr<Node> head;
    
    public:
        LinkedList();
        void insertNode(std::shared_ptr<Node> newNode);
        void deleteNode(int value);
        void findNode(int value);
        void makeCircular();
};